#include "libft.h"

void ft_putstr_fd(char const *s, int fd) {
	if (s) {
		ssize_t ignored __attribute__((unused)) = \
			write(fd, s, ft_strlen(s));
	}
}