#include "../include/libft.h"

void ft_putendl(char const *s) {
	if (s) {
		ssize_t ignored __attribute__((unused)) = \
			write(STDOUT_FILENO, s, ft_strlen(s));
		ft_putchar('\n');
	}
}