#include "libft.h"

char *ft_strnew(size_t size) {
	if (!size) return NULL;
	char *buff = (char *)ft_memalloc(size+1);
	buff[size] = '\0';
	return buff;
}