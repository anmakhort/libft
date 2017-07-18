#include "libft.h"

void ft_putnbr(int n) {
	char *buff = ft_itoa(n);
	ssize_t ignored __attribute__((unused)) = \
		write(STDOUT_FILENO, buff, ft_strlen(buff));
	ft_strdel(&buff);
}