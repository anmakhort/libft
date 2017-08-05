#include "../include/libft.h"

void *ft_memalloc(size_t size) {
	if (!size) return NULL;
	return malloc(size);
}