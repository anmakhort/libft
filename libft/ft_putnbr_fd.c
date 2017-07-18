#include "libft.h"

void ft_putnbr_fd(int n, int fd) {
	char *buff = ft_itoa(n);
	ssize_t ignored __attribute__((unused)) = \
		write(fd, buff, ft_strlen(buff));
	ft_strdel(&buff);
}