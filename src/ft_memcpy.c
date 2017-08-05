#include "../include/libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n) {
	INITIAL_ARG_CHECK(dest, src, n)
	unsigned char *src_ptr = (unsigned char *)src;
	unsigned char *dest_ptr = (unsigned char *)dest;
	while (n--) *(dest_ptr++) = *(src_ptr++);
	return dest;
}