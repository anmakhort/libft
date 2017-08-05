#include "../include/libft.h"

char *ft_strtrim(char const *s) {
	if (!s) return NULL;
	size_t start = 0;
	size_t end = ft_strlen(s)-1;
	while (ft_isspace(s[start])) start++;
	while (ft_isspace(s[end])) end--;
	if (start == end) return NULL;
	else return ft_strsub(s, start, (end-start+1));
}