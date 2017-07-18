#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char)) {
	if (!s || !f) return NULL;
	char *new_str = ft_strnew(ft_strlen(s));
	char *ptr = (char *)s;
	unsigned int idx = 0;
	while (*ptr) {
		new_str[idx] = (*f)(idx,*(ptr++));
		idx++;
	}
	return new_str;
}