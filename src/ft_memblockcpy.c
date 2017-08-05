#include "../include/libft.h"

void *ft_memblockcpy(void *dest, const void * const begin, const void * const end) {
	if (!dest || !begin || !end) return NULL;
	if (begin == end) return dest;
	size_t n = (size_t)((unsigned char*)end-(unsigned char*)begin);
	return ft_memcpy(dest, begin, n);
}