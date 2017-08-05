#include "../include/libft.h"

void ft_strclr(char *s) {
	if (!s) return;
	char *ptr = s;
	while (ptr) *(ptr++) = '\0';
}