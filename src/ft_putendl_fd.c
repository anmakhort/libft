#include "../include/libft.h"

void ft_putendl_fd(char const *s, int fd) {
	if (s) {
		ssize_t ignored __attribute__((unused)) = \
			write(fd, s, ft_strlen(s));
		ft_putchar('\n');
	}
}