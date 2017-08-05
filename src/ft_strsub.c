#include "../include/libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len) {
	if (!s || !len) return NULL;
	if (start >= ft_strlen(s)) return NULL;
	else {
		char *sub = ft_strnew(len);
		return ft_strncpy(sub, s+start, len);
	}
}