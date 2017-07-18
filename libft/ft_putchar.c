#include "libft.h"

void ft_putchar(char c) {
	ssize_t ignored __attribute__((unused)) = \
		write(STDOUT_FILENO, &c, 1);
}