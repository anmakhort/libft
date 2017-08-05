#include "../include/libft.h"

char *ft_strncpy(char *dest, const char *src, size_t n) {
	if (!src || !dest) return NULL;
	if (!n) return dest;
	size_t idx = 0;
	for ( ; idx < n && src[idx]; idx++) dest[idx] = src[idx];
	while (idx < n) dest[idx++] = '\0';
	return dest;
}