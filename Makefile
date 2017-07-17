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
TARGET_LIB = $(TARGET).a

TEST_TARGET = test
TEST_SOURCES = test.c
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)

SOURCES = 	ft_atoi.c \
			ft_atol.c \
			ft_bzero.c \
			ft_free_strsplit.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_islower.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_isxdigit.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstpush_back.c \
			ft_lstpush_front.c \
			ft_ltoa.c \
			ft_memalloc.c \
			ft_memblockcpy.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_n_positions_allocate.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_readline.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_strfind_char.c \
			ft_strfind_str.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strrchr.c \
			ft_strsplit_char.c \
			ft_strsplit_str.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c

OBJECTS = $(SOURCES:.c=.o)

RM = rm -fr

.PHONY: all, run_test, memtest, fulltest, distclean, objclean, clean

all: $(TARGET_LIB) $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CC) -o $(TEST_TARGET) $(TEST_OBJECTS) $(TEST_LDFLAGS) $(TEST_LIBS) -L./$(TARGET_LIB)

$(TEST_OBJECTS):
	$(CC) $(CFLAGS) $(TEST_DEBUG) -c $(TEST_SOURCES) -o $(TEST_OBJECTS)

$(TARGET_LIB): $(OBJECTS)
	ar rc $(TARGET_LIB) $(OBJECTS)
	ranlib $(TARGET_LIB)

%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@

run_test: $(TARGET_LIB) $(TEST_TARGET)
	./$(TEST_TARGET)

memtest: all
	@G_SLICE=always-malloc G_DEBUG=gc-friendly \
	valgrind --tool=memcheck --leak-check=full --leak-check-heuristics=all \
	--show-mismatched-frees=yes --expensive-definedness-checks=yes --show-leak-kinds=all ./$(TEST_TARGET)

fulltest: clean memtest

distclean:
	@$(RM) $(TEST_TARGET) $(TARGET_LIB)

objclean:
	@$(RM) $(OBJECTS) $(TEST_OBJECTS)

clean: distclean objclean
