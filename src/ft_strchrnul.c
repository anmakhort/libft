#include "libft.h"

char *ft_strchrnul(const char *s, int c) {
	if (!s) return NULL;
	char *ptr = (char *)s;
	while (*ptr != c) ptr++;
	return ptr;
}