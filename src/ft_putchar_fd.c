#include "../include/libft.h"

void ft_putchar_fd(char c, int fd) {
	ssize_t ignored __attribute__((unused)) = \
		write(fd, &c, 1);
}