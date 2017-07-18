#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n) {
	INITIAL_ARG_CHECK(dest, src, n)
	void *buff = ft_memalloc(n);
	ft_memcpy(buff, src, n);
	ft_memcpy(dest, buff, n);
	ft_memdel(&buff);
	return dest;
}