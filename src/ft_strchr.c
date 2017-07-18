#include "libft.h"

char *ft_strchr(const char *s, int c) {
	if (!s) return NULL;
	char *ptr = (char *)s;
	while (*ptr && *ptr != c) ptr++;
	if (*ptr != '\0') return ptr;
	else return NULL;
}