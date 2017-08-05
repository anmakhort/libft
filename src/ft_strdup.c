#include "../include/libft.h"

char *ft_strdup(const char *s) {
	if (!s) return NULL;
	char *buff = ft_strnew(ft_strlen(s));
	return ft_strcpy(buff,s);
}