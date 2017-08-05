#################################################################
# Author: Anatolii MAKHORT
# e-mail: anmakhort@gmail.com
#################################################################

CC = gcc
STANDART = -std=c99
CFLAGS = -Wall -Wextra -Werror -O3 -pipe
DEBUG =
INCLUDES = -I/usr/include -I/usr/include/linux -I/include
LDFLAGS =
LIBS =

TEST_STANDART =
TEST_DEBUG = -g
TEST_LDFLAGS =
TEST_LIBS =

TARGET = libft
TARGET_STATIC_LIB = $(TARGET).a
TARGET_SHARED_LIB = $(TARGET).so

TEST_TARGET = ./test/test
TEST_SOURCES = ./test/test.c
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)

SOURCES = \
		./src/ft_lstdelone.c \
		./src/ft_lstadd.c \
		./src/ft_lstdel.c \
		./src/ft_lstiter.c \
		./src/ft_lstmap.c \
		./src/ft_lstnew.c \
		./src/ft_lstpush_front.c \
		./src/ft_lstpush_back.c \
		./src/ft_sign.c \
		./src/ft_bzero.c \
		./src/ft_memalloc.c \
		./src/ft_memblockcpy.c \
		./src/ft_memccpy.c \
		./src/ft_memchr.c \
		./src/ft_memcmp.c \
		./src/ft_memcpy.c \
		./src/ft_memdel.c \
		./src/ft_memmove.c \
		./src/ft_memset.c \
		./src/ft_strcat.c \
		./src/ft_strchr.c \
		./src/ft_strchrnul.c \
		./src/ft_strclr.c \
		./src/ft_strcmp.c \
		./src/ft_strcpy.c \
		./src/ft_strdel.c \
		./src/ft_strdup.c \
		./src/ft_strlen.c \
		./src/ft_strncat.c \
		./src/ft_strncmp.c \
		./src/ft_strncpy.c \
		./src/ft_strndup.c \
		./src/ft_strnew.c \
		./src/ft_strrchr.c \
		./src/ft_strstr.c \
		./src/ft_isascii.c \
		./src/ft_isupper.c \
		./src/ft_islower.c \
		./src/ft_isalpha.c \
		./src/ft_isdigit.c \
		./src/ft_isxdigit.c \
		./src/ft_isalnum.c \
		./src/ft_isspace.c \
		./src/ft_isprint.c \
		./src/ft_toupper.c \
		./src/ft_tolower.c \
		./src/ft_atoi.c \
		./src/ft_atol.c \
		./src/ft_n_digits_int.c \
		./src/ft_n_digits_long.c \
		./src/ft_itoa.c \
		./src/ft_ltoa.c \
		./src/ft_putchar.c \
		./src/ft_putstr.c \
		./src/ft_putendl.c \
		./src/ft_putnbr.c \
		./src/ft_putchar_fd.c \
		./src/ft_putstr_fd.c \
		./src/ft_putendl_fd.c \
		./src/ft_putnbr_fd.c \
		./src/ft_striter.c \
		./src/ft_striteri.c \
		./src/ft_strmap.c \
		./src/ft_strmapi.c \
		./src/ft_strequ.c \
		./src/ft_strnequ.c \
		./src/ft_strsub.c \
		./src/ft_strjoin.c \
		./src/ft_strtrim.c \
		./src/ft_readAll.c \
		./src/ft_getnextline.c \
		./src/ft_strfind_char.c \
		./src/ft_strfind_str.c \
		./src/ft_strsplit_char.c \
		./src/ft_strsplit_str.c \
		./src/ft_free_strsplit.c \
		./src/ft_print_strsplit.c

OBJECTS = $(SOURCES:.c=.o)

RM = rm -fr

.PHONY: all, memtest, fulltest, distclean, objclean, clean

all: newline $(TARGET_STATIC_LIB) $(TARGET_SHARED_LIB) $(TEST_TARGET)

newline:
	@echo ""

$(TARGET_STATIC_LIB): $(OBJECTS)
	@ar rc $(TARGET_STATIC_LIB) $(OBJECTS)
	@ranlib $(TARGET_STATIC_LIB)
	@echo "\033[32m  ✔ \033[0m\033[1;31m" $(TARGET_STATIC_LIB) "\033[0m"

$(TARGET_SHARED_LIB): $(OBJECTS)
	@$(CC) -shared -Wl,-soname,$(TARGET_SHARED_LIB).1 -o $(TARGET_SHARED_LIB).1.0.1 $(OBJECTS)
	@echo "\033[32m  ✔ \033[0m\033[1;31m" $(TARGET_SHARED_LIB).1.0.1 "\033[0m"

%.o: %.c
	@$(CC) $(STANDART) $(CFLAGS) -fPIC $(DEBUG) -c $< -o $@
	@echo "\033[32m  ✔ \033[0m\033[1;33m" $< "\033[0m->\033[1;36m" $@ "\033[0m"

$(TEST_TARGET): $(TEST_OBJECTS) $(TARGET_STATIC_LIB)
	@$(CC) -o $(TEST_TARGET) $(TEST_OBJECTS) $(TEST_LDFLAGS) $(TEST_LIBS) -L. -lft
	@echo "\033[35m  ✔ \033[0m\033[1;36m" $(TEST_OBJECTS) "\033[0m&\033[1;31m" $(TARGET_STATIC_LIB) "\033[0m-> \033[1;34m" $(TEST_TARGET) "\033[0m"

$(TEST_OBJECTS):
	@$(CC) $(TEST_STANDART) $(CFLAGS) $(TEST_DEBUG) -c $(TEST_SOURCES) -o $(TEST_OBJECTS)
	@echo "\033[35m  ✔ \033[0m\033[1;33m" $(TEST_SOURCES) "\033[0m->\033[1;36m" $(TEST_OBJECTS) "\033[0m"

memtest: all
	@G_SLICE=always-malloc G_DEBUG=gc-friendly \
	valgrind --tool=memcheck --leak-check=full --leak-check-heuristics=all \
	--show-mismatched-frees=yes --expensive-definedness-checks=yes --show-leak-kinds=all ./$(TEST_TARGET)

fulltest: clean memtest

distclean:
	@$(RM) $(TEST_TARGET) $(TARGET_LIB) *.so.1* *.a

objclean:
	@$(RM) $(OBJECTS) $(TEST_OBJECTS)

clean: distclean objclean