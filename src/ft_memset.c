#include "../include/libft.h"

void *ft_memset(void *s, int c, size_t n) {
	if (!s) return NULL;
	if (!n) return s;
	unsigned char *ptr = s;
	while (n--) *(ptr++) = (unsigned char)c;
	return s;
}