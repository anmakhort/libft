#include "libft.h"

int ft_strcmp(const char *s1, const char *s2) {
	size_t len = MIN(ft_strlen(s1), ft_strlen(s2));
	return ft_memcmp((const void*)s1, (const void*)s2, len);
}