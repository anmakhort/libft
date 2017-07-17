#include "libft.h"

char *ft_strdup(const char *s) {
	if (!s) return NULL;
	size_t len = ft_strlen(s);
	char *buff = ft_strnew(len);
	return ft_memcpy(buff,s,len);
}