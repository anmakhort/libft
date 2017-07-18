#include "libft.h"

void ft_striter(char *s, void (*f)(char *)) {
	if (!s || !f) return;
	char *ptr = s;
	while (*ptr) (*f)((ptr++));
}