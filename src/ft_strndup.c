#include "../include/libft.h"

char *ft_strndup(const char *s, size_t n) {
	if (!s) return NULL;
	size_t len = MIN(n,ft_strlen(s));
	char *buff = ft_strnew(len);
	return ft_memcpy(buff,s,len);
}