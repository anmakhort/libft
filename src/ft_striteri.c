#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char *)) {
	if (!s || !f) return;
	char *ptr = s;
	unsigned int idx = 0;
	while (*ptr) (*f)((idx++),(ptr++));
}