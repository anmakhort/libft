#include "libft.h"

char *ft_strmap(char const *s, char (*f)(char)) {
	if (!s || !f) return NULL;
	char *new_str = ft_strnew(ft_strlen(s));
	char *ptr = (char *)s;
	size_t idx = 0;
	while (*ptr) new_str[idx++] = (*f)(*(ptr++));
	return new_str;
}