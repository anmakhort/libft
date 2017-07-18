#ifndef UNITTEST_H
#define UNITTEST_H

#include <stdio.h>

#define _ESC_			"\033["
#define _APPLY_			"m"
#define _RESET_ 		_ESC_ "0" _APPLY_

// Text modes:
#define _BOLD_			"1"
#define _DIM_			"2"
#define _ITALIC_		"3"
#define _UNDERLINE_ 	"4"
#define _BLINK_			"5"
#define _REVERSE_		"7"
#define _HIDDEN_		"8"

// Text colors:
#define _FG_BLACK_		"30"
#define _FG_RED_ 		"31"
#define _FG_GREEN_		"32"
#define _FG_YELLOW_		"33"
#define _FG_BLUE_  		"34"
#define _FG_MAGENTA_	"35"
#define _FG_CYAN_		"36"
#define _FG_WHITE_		"37"

// Background colors:
#define _BG_BLACK_		"40"
#define _BG_RED_ 		"41"
#define _BG_GREEN_		"42"
#define _BG_YELLOW_		"43"
#define _BG_BLUE_  		"44"
#define _BG_MAGENTA_	"45"
#define _BG_CYAN_		"46"
#define _BG_WHITE_		"47"

#define COLOR(text,color)			_ESC_ color _APPLY_ text _RESET_
#define BOLD(text,color)			_ESC_ _BOLD_ ";" color _APPLY_ text _RESET_
#define BOLD_ITALIC(text,color)		_ESC_ _BOLD_ ";" _ITALIC_ ";" color _APPLY_ text _RESET_
#define BOLD_UNDERLINE(text,color)	_ESC_ _BOLD_ ";" _UNDERLINE_ ";" color _APPLY_ text _RESET_

#define TEXT_BG_FG(text,bg,fg)				_ESC_ fg ";" bg _APPLY_ text _RESET_
#define TEXT_MODE_BG_FG(text,mode,bg,fg)	_ESC_ mode ";" fg ";" bg _APPLY_ text _RESET_



static unsigned _n_tests_ = 0;
static unsigned _n_passed_ = 0;
static unsigned _n_failed_ = 0;


#define VERBOSE_RUNNING_TESTCASE printf("\nRunning [" BOLD("%s", _FG_BLUE_) "] ...\n", __func__);


#ifdef USE_TESTCASE_COUNTER
static unsigned _n_testcases_ = 0;
#define TESTCASE_COUNTER_INCR ++_n_testcases_;
#define AUTO_TESTCASE_INIT TESTCASE_COUNTER_INCR VERBOSE_RUNNING_TESTCASE
#define _PRINT_STAT_(descr)																\
		printf(BOLD("Test #%i[%i]", _FG_YELLOW_) " {%s} " BOLD("RESULT: ", _FG_CYAN_),	\
				(++_n_tests_),															\
				(_n_testcases_),														\
				descr);
#define _PRINT_RESULTS_																	\
	printf("\n" COLOR("\n Total number of tests:\t",_FG_CYAN_) BOLD("%i ",_FG_YELLOW_)	\
				"[" COLOR("testcases: ", _FG_MAGENTA_) BOLD("%i", _FG_YELLOW_) "]\n"	\
				COLOR("\t\tPASSED:\t",_FG_GREEN_) BOLD("%i\n",_FG_YELLOW_)				\
				COLOR("\t\tFAILED:\t",_FG_RED_) BOLD("%i\n\n",_FG_YELLOW_),				\
				_n_tests_, _n_testcases_, _n_passed_, _n_failed_);
#else
#define AUTO_TESTCASE_INIT VERBOSE_RUNNING_TESTCASE
#define _PRINT_STAT_(descr)															\
		printf(BOLD("Test #%i", _FG_YELLOW_) " {%s} " BOLD("RESULT: ", _FG_CYAN_),	\
				(++_n_tests_),														\
				descr);
#define _PRINT_RESULTS_																	\
	printf("\n" COLOR("\n Total number of tests:\t",_FG_CYAN_) BOLD("%i\n",_FG_YELLOW_)	\
				COLOR("\t\tPASSED:\t",_FG_GREEN_) BOLD("%i\n",_FG_YELLOW_)				\
				COLOR("\t\tFAILED:\t",_FG_RED_) BOLD("%i\n\n",_FG_YELLOW_),				\
				_n_tests_, _n_passed_, _n_failed_);
#endif


#define _TEST_PASSED_	{						\
		++_n_passed_;							\
		printf(BOLD("PASSED",_FG_GREEN_) "\n");	\
	}

#define _TEST_FAILED_	{						\
		++_n_failed_;							\
		printf(BOLD("FAILED",_FG_RED_) "\n");	\
	}




#define TEST_EQUAL(descr,a,b)	\
	_PRINT_STAT_(descr)			\
	if (a == b) _TEST_PASSED_	\
	else _TEST_FAILED_

#define TEST_NOT_EQUAL(descr,a,b)	\
	_PRINT_STAT_(descr)				\
	if (a != b) _TEST_PASSED_		\
	else _TEST_FAILED_

#define TEST_DOUBLE_EQUAL(descr,a,b,c,d)	\
	_PRINT_STAT_(descr)						\
	if ((a == b) && (c == d)) _TEST_PASSED_	\
	else _TEST_FAILED_

#define TEST_DOUBLE_NOT_EQUAL(descr,a,b,c,d)	\
	_PRINT_STAT_(descr)							\
	if ((a != b) && (c != d)) _TEST_PASSED_		\
	else _TEST_FAILED_

#define TEST_GREATER(descr,a,b)	\
	_PRINT_STAT_(descr)			\
	if (a > b) _TEST_PASSED_	\
	else _TEST_FAILED_

#define TEST_LESS(descr,a,b)	\
	_PRINT_STAT_(descr)			\
	if (a < b) _TEST_PASSED_	\
	else _TEST_FAILED_

#define TEST_GREATER_EQUAL(descr,a,b)	\
	_PRINT_STAT_(descr)					\
	if (a >= b) _TEST_PASSED_			\
	else _TEST_FAILED_

#define TEST_LESS_EQUAL(descr,a,b)	\
	_PRINT_STAT_(descr)				\
	if (a <= b) _TEST_PASSED_		\
	else _TEST_FAILED_

#define TEST_MEMORY_EQUAL(descr,buff1,size1,buff2,size2)											\
	_PRINT_STAT_(BOLD_ITALIC("MEMORY: ", _FG_WHITE_) descr)											\
	if (buff1 == buff2) _TEST_PASSED_																\
	else {																							\
		if ((buff1 == NULL) || (buff2 == NULL) || (size1 <= 0) || (size2 <= 0) || (size1 != size2)	\
			|| (sizeof(*buff1) != sizeof(*buff2))) _TEST_FAILED_									\
		else {																						\
			if (memcmp(buff1, buff2, size1) == 0) _TEST_PASSED_										\
			else _TEST_FAILED_																		\
		}																							\
	}


#define TEST_STRINGS_DEEP_EQUAL(descr, ptrptr_str1, ptrptr_str2)	\
	_PRINT_STAT_(BOLD("DEEP_STR_COMP: ", _FG_WHITE_) descr)				\
	if (ptrptr_str1 == ptrptr_str2) _TEST_PASSED_						\
	else {																\
		if (!ptrptr_str1 || !ptrptr_str2) _TEST_FAILED_					\
		else {															\
			char **ptr1 = ptrptr_str1;									\
			char **ptr2 = ptrptr_str2;									\
			int passed = 1;												\
			while (*ptr1 && *ptr2) {									\
				char *ptr_ptr1 = *ptr1;									\
				char *ptr_ptr2 = *ptr2;									\
				while (*ptr_ptr1 != '\0' && *ptr_ptr2 != '\0') {		\
					if (*ptr_ptr1 != *ptr_ptr2) {						\
						passed = 0;										\
						break;											\
					}													\
					ptr_ptr1++;											\
					ptr_ptr2++;											\
				}														\
				if (!passed) break;										\
				ptr1++;													\
				ptr2++;													\
				if (!(*ptr1) && !(*ptr2)) break;						\
				if (!(*ptr1) || !(*ptr2)) {								\
					passed = 0;											\
					break;												\
				}														\
			}															\
			if (passed) _TEST_PASSED_									\
			else _TEST_FAILED_											\
		}																\
	}



#define DUMP_MEMORY_COMP(arr1, arr2, sz_t)				\
	for (size_t i = 0; i < sz_t; i++) {					\
		printf("%i\t%i\n",								\
			((const unsigned char*)((void*)arr1))[i],	\
			((const unsigned char*)((void*)arr2))[i]);	\
	}


#define TEST_CASE(name) void name()
#define SELECT(test_case_name) test_case_name();
#define SELECTED_TEST_CASES void __run_selected__()

#define PERFORM_TESTS int main() {		\
				setbuf(stdout, NULL);	\
				__run_selected__();		\
				_PRINT_RESULTS_			\
				return 0;				\
			}

#endif