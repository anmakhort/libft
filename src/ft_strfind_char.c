#include "../include/libft.h"

char *ft_strfind_char(const char const *s, const char c, size_t *n_conseq) {
	if (!s) return NULL;
	char *found = ft_strchr(s,c);
	if (!found || !n_conseq) return found;
	*n_conseq = 0;
	char *ptr = found;
	while (*(ptr++) == c) ++(*n_conseq);
	return found;
}