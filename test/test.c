#define USE_TESTCASE_COUNTER
#include "unittest.h"

#include "../src/libft.h"
#include <ctype.h>
#include <string.h>


TEST_CASE(ft_memset_test) {
	AUTO_TESTCASE_INIT

	char a[10] = {0,1,2,3,4,5,6,7,8,9};
	char b[10] = {0,1,2,3,4,5,6,7,8,9};
	int v = 0xf;

	char *ft_res = (char*)ft_memset(a, v, 10);
	char *res = (char*)memset(b, v, 10);

	TEST_MEMORY_EQUAL("ft_memset vs memset", a, 10, b, 10)
	TEST_MEMORY_EQUAL("ft_memset vs memset [returned ptrs]", ft_res, 10, res, 10)
}

TEST_CASE(ft_bzero_test) {
	AUTO_TESTCASE_INIT

	char a[10] = {0,1,2,3,4,5,6,7,8,9};
	char b[10] = {0,1,2,3,4,5,6,7,8,9};

	ft_bzero(a, 10);
	bzero(b, 10);

	TEST_MEMORY_EQUAL("ft_bzero vs bzero", a, 10, b, 10)
}

TEST_CASE(ft_memcpy_test) {
	AUTO_TESTCASE_INIT

	char a[10] = {0,1,2,3,4,5,6,7,8,9};
	char b[10] = {0,0,0,0,0,0,0,0,0,0};
	char c[10] = {0,0,0,0,0,0,0,0,0,0};

	char *ft_res = (char*)ft_memcpy(b, a, 10);
	char *res = (char*)memcpy(c, a, 10);

	TEST_MEMORY_EQUAL("ft_memcpy vs memcpy", b, 10, c, 10)
	TEST_MEMORY_EQUAL("ft_memcpy vs memcpy [returned ptrs]", ft_res, 10, res, 10)
}

TEST_CASE(ft_memccpy_test) {
	AUTO_TESTCASE_INIT

	char a[10] = {0,1,2,3,4,5,6,7,8,9};
	char b[10] = {0,0,0,0,0,0,0,0,0,0};
	char c[10] = {0,0,0,0,0,0,0,0,0,0};
	char d[10] = {0,0,0,0,0,0,0,0,0,0};
	int v = 5;

	char *ft_res = (char*)ft_memccpy(b, a, v, 10);
	memccpy(c, a, v, 10);

	char *ft_neg = (char*)ft_memccpy(d, a, 155, 10);

	TEST_EQUAL("Is NULL if stop-val not found", ft_neg, NULL)
	TEST_MEMORY_EQUAL("ft_memccpy vs memccpy", b, 10, c, 10)
	TEST_MEMORY_EQUAL("ft_memccpy vs ft_memccpy [returned ptr]", b, 10, ft_res, 10)
}

TEST_CASE(ft_memmove_test) {
	AUTO_TESTCASE_INIT

	char a[10] = {0,1,2,3,4,5,6,7,8,9};
	char b[10] = {0,0,0,0,0,0,0,0,0,0};
	char c[10] = {0,0,0,0,0,0,0,0,0,0};

	char *ft_res = ft_memmove(b, a, 5);
	char *res = memmove(c, a, 5);

	TEST_MEMORY_EQUAL("ft_memmove vs memmove", b, 10, c, 10)
	TEST_MEMORY_EQUAL("ft_memmove vs memmove [returned ptrs]", ft_res, 10, res, 10)
}

TEST_CASE(ft_memchr_test) {
	AUTO_TESTCASE_INIT

	char a[10] = {0,1,2,3,4,5,6,7,8,9};
	char v = 5;

	char *ft_res = ft_memchr(a, v, 10);
	char *res = memchr(a, v, 10);
	char *ft_neg = ft_memchr(a, 155, 10);

	TEST_EQUAL("Dereferenced == searched-for", *ft_res, v)
	TEST_EQUAL("[ret ptr]ft_memmove == [ret ptr]memmove", ft_res, res)
	TEST_EQUAL("Is NULL if stop-char not found", ft_neg, NULL)
}

TEST_CASE(ft_memcmp_test) {
	AUTO_TESTCASE_INIT

	char a[] = "abcdef";
	char b[] = "ABCDEF";

	int ft_res = ft_memcmp(a, b, 6);
	int res = memcmp(a, b, 6);

	TEST_EQUAL("[ret]ft_memcmp == [ret]memcmp", ft_res, res)
	TEST_GREATER("[ret]ft_memcmp > 0", ft_res, 0)
}

TEST_CASE(ft_strlen_test) {
	AUTO_TESTCASE_INIT

	const char *str = "Hello World!";

	size_t ft_res = ft_strlen(str);
	size_t res = strlen(str);
	size_t ft_neg = ft_strlen("");

	TEST_EQUAL("[ret]ft_strlen == [ret]strlen", ft_res, res)
	TEST_EQUAL("Is '0' if '' putted", ft_neg, 0)
}

TEST_CASE(ft_strdup_test) {
	AUTO_TESTCASE_INIT

	const char *str = "Hello World!";

	char *ft_res = ft_strdup(str);
	char *res = strdup(str);
	
	TEST_MEMORY_EQUAL("[ret]ft_strdup == [ret]strdup", ft_res, strlen(ft_res), res, strlen(res))
	TEST_MEMORY_EQUAL("[ret]ft_strdup == putted", ft_res, strlen(ft_res), str, strlen(str))

	free(ft_res);
	free(res);
}

TEST_CASE(ft_strcpy_test) {
	AUTO_TESTCASE_INIT

	const char *str = "Hello World!";

	char *a = (char*)malloc(strlen(str)+1);
	char *b = (char*)malloc(strlen(str)+1);

	char *ft_res = ft_strcpy(a, str);
	char *res = strcpy(b, str);
	
	TEST_MEMORY_EQUAL("[ret]ft_strcpy == [ret]strcpy", a, strlen(a), b, strlen(b))
	TEST_MEMORY_EQUAL("[ret ptr]ft_strcpy == [ret ptr]strcpy", ft_res, strlen(ft_res), res, strlen(res))
	TEST_MEMORY_EQUAL("[ret]ft_strcpy == putted", a, strlen(a), str, strlen(str))
	TEST_MEMORY_EQUAL("[ret ptr]ft_strcpy == putted", ft_res, strlen(ft_res), str, strlen(str))

	free(a);
	free(b);
}

TEST_CASE(ft_strncpy_test) {
	AUTO_TESTCASE_INIT

	const char *str = "Hello World!";

	char *a = (char*)malloc(12+1);
	char *b = (char*)malloc(12+1);
	char *c = (char*)malloc(5);
	char *d = (char*)malloc(5);
	char *e = (char*)malloc(30);
	char *f = (char*)malloc(30);

	char *ft_res = ft_strncpy(a, str, 12);
	char *res = strncpy(b, str, 12);

	char *ft_part_res = ft_strncpy(c, str, 5);
	char *part_res = strncpy(d, str, 5);

	const char *correct = "Hello";

	char *ft_part2_res = ft_strncpy(e, str, 30);
	char *part2_res = strncpy(f, str, 30);
	
	TEST_MEMORY_EQUAL("[ret]ft_strncpy == [ret]strncpy", a, 12, b, 12)
	TEST_MEMORY_EQUAL("[ret ptr]ft_strncpy == [ret ptr]strncpy", ft_res, 12, res, 12)
	TEST_MEMORY_EQUAL("[ret]ft_strncpy == putted", a, 12, str, 12)
	TEST_MEMORY_EQUAL("[ret ptr]ft_strncpy == putted", ft_res, 12, str, 12)
	TEST_MEMORY_EQUAL("(Partial < size):[ret]ft_strncpy == [ret]strncpy", c, 5, d, 5)
	TEST_MEMORY_EQUAL("(Partial < size):[ret ptr]ft_strncpy == [ret ptr]strncpy", ft_part_res, 5, part_res, 5)
	TEST_MEMORY_EQUAL("(Partial < size):[ret ptr]ft_strncpy == correct", ft_part_res, 5, correct, 5)
	TEST_MEMORY_EQUAL("(Partial > size):[ret ptr]ft_strncpy == [ret ptr]strncpy", ft_part2_res, 30, part2_res, 30)

	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);
}

TEST_CASE(ft_strcat_test) {
	AUTO_TESTCASE_INIT

	const char *str1 = "Hello";
	const char *str2 = " World!";
	const char *correct = "Hello World!";

	char *a = (char*)malloc(12+1);
	char *b = (char*)malloc(12+1);

	memset(a, 0, 12+1);
	memset(b, 0, 12+1);

	memcpy(a, str1, 5);
	memcpy(b, str1, 7);

	char *ft_res = ft_strcat(a, str2);
	char *res = strcat(b, str2);

	TEST_MEMORY_EQUAL("[ret]ft_strcat == [ret]strcat", a, 12+1, b, 12+1)
	TEST_MEMORY_EQUAL("[ret ptr]ft_strcat == [ret ptr]strcat", ft_res, 12+1, res, 12+1)
	TEST_MEMORY_EQUAL("[ret]ft_strcat == correct", a, 12, correct, 12)
	TEST_MEMORY_EQUAL("[ret ptr]ft_strcat == correct", ft_res, 12, correct, 12)
	
	free(a);
	free(b);
}

TEST_CASE(ft_strncat_test) {
	AUTO_TESTCASE_INIT

	const char *str1 = "Hello";
	const char *str2 = " World!";

	const char *correct = "Hello World!";
	const char *correct2 = "Hello Worl";

	char *a = (char*)malloc(strlen(correct)+1);
	char *b = (char*)malloc(strlen(correct)+1);
	char *c = (char*)malloc(strlen(str1)+6);
	char *d = (char*)malloc(strlen(str1)+6);
	char *e = (char*)malloc(strlen(str1)+31);
	char *f = (char*)malloc(strlen(str1)+31);

	memset(a, 0, strlen(correct)+1);
	memset(b, 0, strlen(correct)+1);
	memset(c, 0, strlen(str1)+6);
	memset(d, 0, strlen(str1)+6);
	memset(e, 0, strlen(str1)+31);
	memset(f, 0, strlen(str1)+31);

	memcpy(a, str1, strlen(str1));
	memcpy(b, str1, strlen(str1));
	memcpy(c, str1, strlen(str1));
	memcpy(d, str1, strlen(str1));
	memcpy(e, str1, strlen(str1));
	memcpy(f, str1, strlen(str1));

	char *ft_res = ft_strncat(a, str2, strlen(str2));
	char *res = strncat(b, str2, strlen(str2));

	char *ft_part_res = ft_strncat(c, str2, 5);
	char *part_res = strncat(d, str2, 5);

	char *ft_part2_res = ft_strncat(e, str2, 30);
	char *part2_res = strncat(f, str2, 30);

	TEST_MEMORY_EQUAL("[ret]ft_strcat == [ret]strcat", a, 12+1, b, 12+1)
	TEST_MEMORY_EQUAL("[ret ptr]ft_strcat == [ret ptr]strcat", ft_res, 12+1, res, 12+1)
	TEST_MEMORY_EQUAL("[ret]ft_strcat == correct", a, 12, correct, 12)
	TEST_MEMORY_EQUAL("[ret ptr]ft_strcat == correct", ft_res, strlen(ft_res), correct, 12)
	TEST_MEMORY_EQUAL("(Partial < size):[ret]ft_strncat == [ret]strncat", c, strlen(str1)+6, d, strlen(str1)+6)
	TEST_MEMORY_EQUAL("(Partial < size):[ret ptr]ft_strncat == [ret ptr]strncat", ft_part_res, strlen(str1)+6, part_res, strlen(str1)+6)
	TEST_MEMORY_EQUAL("(Partial < size):[ret ptr]ft_strncpy == correct", ft_part_res, strlen(correct2), correct2, strlen(correct2))
	TEST_MEMORY_EQUAL("(Partial > size):[ret ptr]ft_strncpy == [ret ptr]strncpy", ft_part2_res, strlen(str1)+31, part2_res, strlen(str1)+31)
	
	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);
}

TEST_CASE(ft_strchr_test) {
	AUTO_TESTCASE_INIT

	const char *str = "Hello World!";
	const char v = 'W';

	char *ft_res = ft_strchr(str, v);
	char *res = strchr(str, v);
	char *ft_neg = ft_strchr(str, '1');

	TEST_EQUAL("[ret]ft_strchr == [ret]strchr", ft_res, res)
	TEST_EQUAL("Dereferenced [ret ptr]ft_strchr == correct", *ft_res, v)
	TEST_EQUAL("Location test [ret ptr]ft_strchr", (int)(ft_res-str), 6)
	TEST_EQUAL("Is NULL when not found", ft_neg, NULL)
}

TEST_CASE(ft_strrchr_test) {
	AUTO_TESTCASE_INIT

	const char *str = "Hello World!";
	const char v = 'o';

	char *ft_res = ft_strrchr(str, v);
	char *res = strrchr(str, v);
	char *ft_neg = ft_strrchr(str, '1');

	TEST_EQUAL("[ret]ft_strrchr == [ret]strrchr", ft_res, res)
	TEST_EQUAL("Dereferenced [ret ptr]ft_strrchr == correct", *ft_res, v)
	TEST_EQUAL("Location test [ret ptr]ft_strrchr", (int)(ft_res-str), 7)
	TEST_EQUAL("Is NULL when not found", ft_neg, NULL)
}

TEST_CASE(ft_strstr_test) {
	AUTO_TESTCASE_INIT

	const char *str = "Hello World!";
	const char *pattern = "Wor";

	char *ft_res = ft_strstr(str, pattern);
	char *res = strstr(str, pattern);
	char *ft_neg = ft_strstr(str, "111");

	TEST_EQUAL("[ret]ft_strstr == [ret]strstr", ft_res, res)
	TEST_EQUAL("[ret ptr]ft_strstr == correct", ft_res, str+6)
	TEST_EQUAL("Is NULL when not found", ft_neg, NULL)
}

TEST_CASE(ft_strcmp_test) {
	AUTO_TESTCASE_INIT

	const char *str1 = "Hello";
	const char *str2 = "hello";
	const char *str3 = "he";
	const char *str4 = "Hello";

	int ft_res = ft_strcmp(str1, str2);
	int ft_res2 = ft_strcmp(str1, str3);
	int ft_res3 = ft_strcmp(str1, str4);

	TEST_LESS("[ret]ft_strcmp < 0", ft_res, 0)
	TEST_LESS("(Not equi-sized) [ret]ft_strcmp < 0", ft_res2, 0)
	TEST_EQUAL("(Same strings) [ret]ft_strcmp == 0", ft_res3, 0)
}

TEST_CASE(ft_strncmp_test) {
	AUTO_TESTCASE_INIT

	const char *str1 = "Hello";
	const char *str2 = "hello";
	const char *str3 = "he";
	const char *str4 = "Hello";

	int ft_res = ft_strncmp(str1, str2, 3);
	int ft_res2 = ft_strncmp(str1, str3, 5);
	int ft_res3 = ft_strcmp(str1, str4);
	
	TEST_LESS("[ret]ft_strncmp < 0", ft_res, 0)
	TEST_LESS("(Not equi-sized) [ret]ft_strncmp < 0", ft_res2, 0)
	TEST_EQUAL("(Same strings) [ret]ft_strncmp == 0", ft_res3, 0)
}

TEST_CASE(ft_isascii_test) {
	AUTO_TESTCASE_INIT
	
	TEST_EQUAL("[ret]ft_isascii(0) == [ret]isascii(0)", ft_isascii('\0'), isascii('\0'))
	TEST_EQUAL("[ret]ft_isascii('q') == 1", ft_isascii('q'), 1)
	TEST_EQUAL("[ret]ft_isascii('4') == 1", ft_isascii('4'), 1)
	TEST_EQUAL("[ret]ft_isascii('{') == 1", ft_isascii('{'), 1)
	TEST_EQUAL("[ret]ft_isascii(127) == 1", ft_isascii(127), 1)
	TEST_EQUAL("[ret]ft_isascii(128) == [ret]isascii(128)", ft_isascii(128), isascii(128))
}

TEST_CASE(ft_isupper_test) {
	AUTO_TESTCASE_INIT

	TEST_EQUAL("[ret]ft_isupper('0') == [ret]isupper('0')", ft_isupper('0'), isupper('0'))
	TEST_EQUAL("[ret]ft_isupper('q') == 0", ft_isupper('q'), 0)
	TEST_EQUAL("[ret]ft_isupper('A') == 1", ft_isupper('A'), 1)
	TEST_EQUAL("[ret]ft_isupper('{') == 0", ft_isupper('{'), 0)
	TEST_EQUAL("[ret]ft_isupper(128) == [ret]isupper(128)", ft_isupper(128), isupper(128))
}

TEST_CASE(ft_islower_test) {
	AUTO_TESTCASE_INIT
	
	TEST_EQUAL("[ret]ft_islower('0') == [ret]islower('0')", ft_islower('0'), islower('0'))
	TEST_EQUAL("[ret]ft_islower('q') == 1", ft_islower('q'), 1)
	TEST_EQUAL("[ret]ft_islower('A') == 0", ft_islower('A'), 0)
	TEST_EQUAL("[ret]ft_islower('{') == 0", ft_islower('{'), 0)
	TEST_EQUAL("[ret]ft_islower(128) == [ret]islower(128)", ft_islower(128), islower(128))
}

TEST_CASE(ft_isalpha_test) {
	AUTO_TESTCASE_INIT
	
	TEST_EQUAL("[ret]ft_isalpha('0') == [ret]isalpha('0')", ft_isalpha('0'), isalpha('0'))
	TEST_EQUAL("[ret]ft_isalpha('q') == 1", ft_isalpha('q'), 1)
	TEST_EQUAL("[ret]ft_isalpha('E') == 1", ft_isalpha('E'), 1)
	TEST_EQUAL("[ret]ft_isalpha('{') == 0", ft_isalpha('+'), 0)
	TEST_EQUAL("[ret]ft_isalpha(128) == [ret]isalpha(128)", ft_isalpha(128), isalpha(128))
}

TEST_CASE(ft_isdigit_test) {
	AUTO_TESTCASE_INIT

	TEST_EQUAL("[ret]ft_isdigit('0') == 1", ft_isdigit('0'), 1)
	TEST_EQUAL("[ret]ft_isdigit('q') == 0", ft_isdigit('q'), 0)
	TEST_EQUAL("[ret]ft_isdigit('E') == 0", ft_isdigit('E'), 0)
	TEST_EQUAL("[ret]ft_isdigit('+') == 0", ft_isdigit('+'), 0)
	TEST_EQUAL("[ret]ft_isdigit(128) == [ret]isdigit(128)", ft_isdigit(128), isdigit(128))
}

TEST_CASE(ft_isxdigit_test) {
	AUTO_TESTCASE_INIT
	
	TEST_EQUAL("[ret]ft_isxdigit('0') == 1", ft_isxdigit('0'), 1)
	TEST_EQUAL("[ret]ft_isxdigit('q') == 0", ft_isxdigit('q'), 0)
	TEST_EQUAL("[ret]ft_isxdigit('e') == 1", ft_isxdigit('e'), 1)
	TEST_EQUAL("[ret]ft_isxdigit('E') == 1", ft_isxdigit('E'), 1)
	TEST_EQUAL("[ret]ft_isxdigit('+') == 0", ft_isxdigit('+'), 0)
	TEST_EQUAL("[ret]ft_isxdigit(128) == [ret]isxdigit(128)", ft_isxdigit(128), isxdigit(128))
}

TEST_CASE(ft_isalnum_test) {
	AUTO_TESTCASE_INIT

	TEST_EQUAL("[ret]ft_isalnum('0') == 1", ft_isalnum('0'), 1)
	TEST_EQUAL("[ret]ft_isalnum('q') == 1", ft_isalnum('q'), 1)
	TEST_EQUAL("[ret]ft_isalnum('E') == 1", ft_isalnum('E'), 1)
	TEST_EQUAL("[ret]ft_isalnum('+') == 0", ft_isalnum('+'), 0)
	TEST_EQUAL("[ret]ft_isalnum(128) == [ret]isalnum(128)", ft_isalnum(128), isalnum(128))
}

TEST_CASE(ft_isspace_test) {
	AUTO_TESTCASE_INIT

	TEST_EQUAL("[ret]ft_isspace('0') == [ret]isspace('0')", ft_isspace('0'), isspace('0'))
	TEST_EQUAL("[ret]ft_isspace('q') == 0", ft_isspace('q'), 0)
	TEST_EQUAL("[ret]ft_isspace(space) == 1", ft_isspace(' '), 1)
	TEST_EQUAL("[ret]ft_isspace(tab) == 1", ft_isspace('\t'), 1)
	TEST_EQUAL("[ret]ft_isspace(newline) == 1", ft_isspace('\n'), 1)
}

TEST_CASE(ft_isprint_test) {
	AUTO_TESTCASE_INIT

	TEST_EQUAL("[ret]ft_isprint(54) == 1", ft_isprint(54), 1)
	TEST_EQUAL("[ret]ft_isprint('*') == 1", ft_isprint('*'), 1)
	TEST_EQUAL("[ret]ft_isprint(200) == 0", ft_isprint(200), 0)
	TEST_EQUAL("[ret]ft_isprint(space) == 1", ft_isprint(' '), 1)
	TEST_EQUAL("[ret]ft_isprint(newline) == 0", ft_isprint('\n'), 0)
	TEST_EQUAL("[ret]ft_isprint(tab) == 0", ft_isprint('\t'), 0)
	TEST_EQUAL("[ret]ft_isprint(vtab) == 0", ft_isprint('\v'), 0)
	TEST_EQUAL("[ret]ft_isprint(cr) == 0", ft_isprint('\r'), 0)
	TEST_EQUAL("[ret]ft_isprint(128) == [ret]isprint(128)", ft_isprint(128), isprint(128))
}

TEST_CASE(ft_toupper_test) {
	AUTO_TESTCASE_INIT

	TEST_EQUAL("[ret]ft_toupper('5') == [ret]toupper('5')", ft_toupper('5'), toupper('5'))
	TEST_EQUAL("[ret]ft_toupper('*') == '*'", ft_toupper('*'), '*')
	TEST_EQUAL("[ret]ft_toupper('R') == 'R'", ft_toupper('R'), 'R')
	TEST_EQUAL("[ret]ft_toupper('g') == 'G'", ft_toupper('g'), 'G')
	TEST_EQUAL("[ret]ft_toupper(128) == [ret]toupper(128)", ft_toupper(128), toupper(128))
}

TEST_CASE(ft_tolower_test) {
	AUTO_TESTCASE_INIT

	TEST_EQUAL("[ret]ft_tolower('5') == [ret]tolower('5')", ft_tolower('5'), tolower('5'))
	TEST_EQUAL("[ret]ft_tolower('*') == '*'", ft_tolower('*'), '*')
	TEST_EQUAL("[ret]ft_tolower('Q') == 'q'", ft_tolower('Q'), 'q')
	TEST_EQUAL("[ret]ft_tolower('g') == 'g'", ft_tolower('g'), 'g')
	TEST_EQUAL("[ret]ft_tolower(128) == [ret]tolower(128)", ft_tolower(128), tolower(128))
}

TEST_CASE(ft_atoi_test) {
	AUTO_TESTCASE_INIT

	TEST_EQUAL("[ret]ft_atoi(\"-125\") == [ret]atoi(\"-125\")", ft_atoi("-125"), atoi("-125"))
	TEST_EQUAL("[ret]ft_atoi(\"125\") == [ret]atoi(\"125\")", ft_atoi("125"), atoi("125"))
	TEST_EQUAL("[ret]ft_atoi(\"  -125\") == [ret]atoi(\"  -125\")", ft_atoi("  -125"), atoi("  -125"))
	TEST_EQUAL("[ret]ft_atoi(\"\t125\") == [ret]atoi(\"\t125\")", ft_atoi("\t125"), atoi("\t125"))
	TEST_EQUAL("[ret]ft_atoi(\"--125\") == [ret]atoi(\"--125\")", ft_atoi("--125"), atoi("--125"))
	TEST_EQUAL("[ret]ft_atoi(\"12.5\") == [ret]atoi(\"12.5\")", ft_atoi("12.5"), atoi("12.5"))
	TEST_EQUAL("[ret]ft_atoi(\"qwerty\") == [ret]atoi(\"qwerty\")", ft_atoi("qwerty"), atoi("qwerty"))
}

TEST_CASE(ft_atol_test) {
	AUTO_TESTCASE_INIT
	
	TEST_EQUAL("[ret]ft_atol(\"-125\") == [ret]atol(\"-125\")", ft_atol("-125"), atol("-125"))
	TEST_EQUAL("[ret]ft_atol(\"125\") == [ret]atol(\"125\")", ft_atol("125"), atol("125"))
	TEST_EQUAL("[ret]ft_atol(\"  -125\") == [ret]atol(\"  -125\")", ft_atol("  -125"), atol("  -125"))
	TEST_EQUAL("[ret]ft_atol(\"\t125\") == [ret]atol(\"\t125\")", ft_atol("\t125"), atol("\t125"))
	TEST_EQUAL("[ret]ft_atol(\"--125\") == [ret]atol(\"--125\")", ft_atol("--125"), atol("--125"))
	TEST_EQUAL("[ret]ft_atol(\"12.5\") == [ret]atol(\"12.5\")", ft_atol("12.5"), atol("12.5"))
	TEST_EQUAL("[ret]ft_atol(\"qwerty\") == [ret]atol(\"qwerty\")", ft_atol("qwerty"), atol("qwerty"))
}

TEST_CASE(ft_itoa_test) {
	AUTO_TESTCASE_INIT

	char *num1 = ft_itoa(125);
	char *num2 = ft_itoa(-125);
	char *num3 = ft_itoa(0);
	char *num4 = ft_itoa(1);
	char *num5 = ft_itoa(-1);
	char *num6 = ft_itoa(1234567890);

	const char *correct1 = "125";
	const char *correct2 = "-125";
	const char *correct3 = "0";
	const char *correct4 = "1";
	const char *correct5 = "-1";
	const char *correct6 = "1234567890";

	TEST_MEMORY_EQUAL("[ret ptr]ft_itoa(125) == \"125\"", num1, 3, correct1, 3)
	TEST_MEMORY_EQUAL("[ret ptr]ft_itoa(-125) == \"-125\"", num2, 4, correct2, 4)
	TEST_MEMORY_EQUAL("[ret ptr]ft_itoa(0) == \"0\"", num3, 1, correct3, 1)
	TEST_MEMORY_EQUAL("[ret ptr]ft_itoa(1) == \"1\"", num4, 1, correct4, 1)
	TEST_MEMORY_EQUAL("[ret ptr]ft_itoa(-1) == \"-1\"", num5, 2, correct5, 2)
	TEST_MEMORY_EQUAL("[ret ptr]ft_itoa(1234567890) == \"1234567890\"", num6, 10, correct6, 10)

	ft_strdel(&num1);
	ft_strdel(&num2);
	ft_strdel(&num3);
	ft_strdel(&num4);
	ft_strdel(&num5);
	ft_strdel(&num6);
}

TEST_CASE(ft_ltoa_test) {
	AUTO_TESTCASE_INIT

	char *num1 = ft_ltoa(125);
	char *num2 = ft_ltoa(-125);
	char *num3 = ft_ltoa(0);
	char *num4 = ft_ltoa(1);
	char *num5 = ft_ltoa(-1);
	char *num6 = ft_ltoa(1234567890);

	const char *correct1 = "125";
	const char *correct2 = "-125";
	const char *correct3 = "0";
	const char *correct4 = "1";
	const char *correct5 = "-1";
	const char *correct6 = "1234567890";

	TEST_MEMORY_EQUAL("[ret ptr]ft_ltoa(125) == \"125\"", num1, 3, correct1, 3)
	TEST_MEMORY_EQUAL("[ret ptr]ft_ltoa(-125) == \"-125\"", num2, 4, correct2, 4)
	TEST_MEMORY_EQUAL("[ret ptr]ft_ltoa(0) == \"0\"", num3, 1, correct3, 1)
	TEST_MEMORY_EQUAL("[ret ptr]ft_ltoa(1) == \"1\"", num4, 1, correct4, 1)
	TEST_MEMORY_EQUAL("[ret ptr]ft_ltoa(-1) == \"-1\"", num5, 2, correct5, 2)
	TEST_MEMORY_EQUAL("[ret ptr]ft_ltoa(1234567890) == \"1234567890\"", num6, 10, correct6, 10)

	ft_strdel(&num1);
	ft_strdel(&num2);
	ft_strdel(&num3);
	ft_strdel(&num4);
	ft_strdel(&num5);
	ft_strdel(&num6);
}


void f(char *c) {
	if (c) *c = ft_toupper(*c);
}

TEST_CASE(ft_striter_test) {
	AUTO_TESTCASE_INIT

	char str[] = "qwerty!";
	const char *correct = "QWERTY!";
	
	ft_striter(str, f);

	TEST_MEMORY_EQUAL("Check to-upper-case by iteration", str, ft_strlen(str), correct, ft_strlen(correct))
}


void f2(unsigned int i, char *c) {
	char *buff = ft_itoa(i);
	if (c) *c = buff[0];
	free(buff);
}

TEST_CASE(ft_striteri_test) {
	AUTO_TESTCASE_INIT

	char str[] = "qwerty!";
	const char *correct = "0123456";
	
	ft_striteri(str, f2);

	TEST_MEMORY_EQUAL("Check indexing by iteration", str, ft_strlen(str), correct, ft_strlen(correct))
}

/*
char f3(char c) {
	return ft_toupper(c);
}

TEST_CASE(ft_strmap_test) {
	AUTO_TESTCASE_INIT

	const char *correct = "QWERTY!";
	char *ft_res = ft_strmap("qwerty!", f3);

	TEST_MEMORY_EQUAL("Check to-upper-case by iteration", ft_res, ft_strlen(ft_res), correct, ft_strlen(correct))

	ft_strdel(&ft_res);
}


char f4(unsigned int idx, char c) {
	return (char)idx + c;
}

TEST_CASE(ft_strmapi_test) {
	AUTO_TESTCASE_INIT

	const char *correct = "012345";
	char *ft_res = ft_strmapi("000000", f4);
	
	TEST_MEMORY_EQUAL("Check char increment by iteration", ft_res, ft_strlen(ft_res), correct, ft_strlen(correct))

	ft_strdel(&ft_res);
}

TEST_CASE(ft_strsplit_test) {
	AUTO_TESTCASE_INIT

	char **splitted = ft_strsplit("**salut*les***etudiants*", '*');
	char **splitted2 = ft_strsplit("*salut**les**etudiants*", "*");
	char **splitted3 = ft_strsplit("**salut**les**etudiants**", "**");

	TEST_STRINGS_DEEP_EQUAL("ft_strsplit by single char", splitted, splitted2)
	TEST_STRINGS_DEEP_EQUAL("ft_strsplit by string", splitted2, splitted3)

	ft_free_strsplit(&splitted);
	ft_free_strsplit(&splitted2);
	ft_free_strsplit(&splitted3);
}
*/

SELECTED_TEST_CASES {
	SELECT(ft_memset_test)
	SELECT(ft_bzero_test)
	SELECT(ft_memcpy_test)
	SELECT(ft_memccpy_test)
	SELECT(ft_memmove_test)
	SELECT(ft_memchr_test)
	SELECT(ft_memcmp_test)
	SELECT(ft_strlen_test)
	SELECT(ft_strdup_test)
	SELECT(ft_strcpy_test)
	SELECT(ft_strncpy_test)
	SELECT(ft_strcat_test)
	SELECT(ft_strncat_test)
	SELECT(ft_strchr_test)
	SELECT(ft_strrchr_test)
	SELECT(ft_strstr_test)
	SELECT(ft_strcmp_test)
	SELECT(ft_strncmp_test)
	SELECT(ft_isascii_test)
	SELECT(ft_isupper_test)
	SELECT(ft_islower_test)
	SELECT(ft_isalpha_test)
	SELECT(ft_isdigit_test)
	SELECT(ft_isxdigit_test)
	SELECT(ft_isalnum_test)
	SELECT(ft_isspace_test)
	SELECT(ft_isprint_test)
	SELECT(ft_toupper_test)
	SELECT(ft_tolower_test)
	SELECT(ft_atoi_test)
	SELECT(ft_atol_test)
	SELECT(ft_itoa_test)
	SELECT(ft_ltoa_test)
	SELECT(ft_striter_test)
	SELECT(ft_striteri_test)
	//SELECT(ft_strmap_test)
	//SELECT(ft_strmapi_test)
	//SELECT(ft_strsplit_test)
}

PERFORM_TESTS