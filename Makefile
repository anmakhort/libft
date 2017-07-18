#################################################################
# Author: Anatolii MAKHORT
# e-mail: anmakhort@gmail.com
#################################################################

CC = gcc
STANDART = -std=c99
CFLAGS = -Wall -Wextra -Werror -O3 -pipe
DEBUG =
INCLUDES = -I/usr/include -I/usr/include/linux -I/libft/
LDFLAGS =
LIBS =

TEST_STANDART =
TEST_DEBUG = -g
TEST_LDFLAGS =
TEST_LIBS =

TARGET = libft
TARGET_STATIC_LIB = $(TARGET).a
TARGET_SHARED_LIB = $(TARGET).so

TEST_TARGET = test
TEST_SOURCES = test.c
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)

SOURCES = 	./libft/ft_bzero.c \
./libft/ft_memalloc.c \
./libft/ft_memblockcpy.c \
./libft/ft_memccpy.c \
./libft/ft_memchr.c \
./libft/ft_memcmp.c \
./libft/ft_memcpy.c \
./libft/ft_memdel.c \
./libft/ft_memmove.c \
./libft/ft_memset.c \
./libft/ft_strcat.c \
./libft/ft_strchr.c \
./libft/ft_strchrnul.c \
./libft/ft_strclr.c \
./libft/ft_strcmp.c \
./libft/ft_strcpy.c \
./libft/ft_strdel.c \
./libft/ft_strdup.c \
./libft/ft_strlen.c \
./libft/ft_strncat.c \
./libft/ft_strncmp.c \
./libft/ft_strncpy.c \
./libft/ft_strndup.c \
./libft/ft_strnew.c \
./libft/ft_strrchr.c \
./libft/ft_strstr.c \
./libft/ft_isascii.c \
./libft/ft_isupper.c \
./libft/ft_islower.c \
./libft/ft_isalpha.c \
./libft/ft_isdigit.c \
./libft/ft_isxdigit.c \
./libft/ft_isalnum.c \
./libft/ft_isspace.c \
./libft/ft_isprint.c \
./libft/ft_toupper.c \
./libft/ft_tolower.c \
./libft/ft_atoi.c \
./libft/ft_atol.c \
./libft/ft_n_digits_int.c \
./libft/ft_n_digits_long.c \
./libft/ft_itoa.c \
./libft/ft_ltoa.c

OBJECTS = $(SOURCES:.c=.o)

RM = rm -fr

.PHONY: all, run, memtest, fulltest, distclean, objclean, clean

all: newline $(TARGET_STATIC_LIB) $(TARGET_SHARED_LIB) $(TEST_TARGET)

newline:
	@echo ""

$(TARGET_STATIC_LIB): $(OBJECTS)
	@echo "\033[32m  ✔ \033[0m\033[1;31m" $(TARGET_STATIC_LIB) "\033[0m"
	@ar rc $(TARGET_STATIC_LIB) $(OBJECTS)
	@ranlib $(TARGET_STATIC_LIB)

$(TARGET_SHARED_LIB): $(OBJECTS)
	@echo "\033[32m  ✔ \033[0m\033[1;31m" $(TARGET_SHARED_LIB).1.0.1 "\033[0m"
	@$(CC) -shared -Wl,-soname,$(TARGET_SHARED_LIB).1 -o $(TARGET_SHARED_LIB).1.0.1 $(OBJECTS)

%.o: %.c
	@echo "\033[32m  ✔ \033[0m\033[1;33m" $< "\033[0m->\033[1;36m" $@ "\033[0m"
	@$(CC) $(STANDART) $(CFLAGS) -fPIC $(DEBUG) -c $< -o $@

$(TEST_TARGET): $(TEST_OBJECTS) $(TARGET_STATIC_LIB)
	@echo "\033[35m  ✔ \033[0m\033[1;36m" $(TEST_OBJECTS) "\033[0m&\033[1;31m" $(TARGET_STATIC_LIB) "\033[0m-> \033[1;34m" $(TEST_TARGET) "\033[0m"
	@$(CC) -o $(TEST_TARGET) $(TEST_OBJECTS) $(TEST_LDFLAGS) $(TEST_LIBS) -L. -lft

$(TEST_OBJECTS):
	@echo "\033[35m  ✔ \033[0m\033[1;33m" $(TEST_SOURCES) "\033[0m->\033[1;36m" $(TEST_OBJECTS) "\033[0m"
	@$(CC) $(TEST_STANDART) $(CFLAGS) $(TEST_DEBUG) -c $(TEST_SOURCES) -o $(TEST_OBJECTS)

run: $(TEST_TARGET) newline
	./$(TEST_TARGET)

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