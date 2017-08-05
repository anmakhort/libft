#include "../include/libft.h"

char *ft_strjoin(char const *s1, char const *s2) {
	if (!s1) return ft_strdup(s2);
	if (!s2) return ft_strdup(s1);
	size_t n = ft_strlen(s1);
	char *buff = ft_strnew(n+ft_strlen(s2));
	if (!ft_strcpy(buff, s1)) return NULL;
	ft_strcpy(buff+n, s2);
	return buff;
}