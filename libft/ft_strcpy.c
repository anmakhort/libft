#include "libft.h"

char *ft_strcpy(char *dest, const char *src) {
	if (!src || !dest) return NULL;
	return ft_memcpy((void*)dest, (void*)src, ft_strlen(src)+1);
}