#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n) {
	size_t len = MIN(n, MIN(ft_strlen(s1), ft_strlen(s2)));
	return ft_memcmp((const void*)s1, (const void*)s2, len);
}