#include "../include/libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n) {
	INITIAL_ARG_CHECK(dest, src, n)
	unsigned char *src_ptr = (unsigned char *)src;
	unsigned char *dest_ptr = (unsigned char *)dest;
	while (n--) {
		*(dest_ptr++) = *(src_ptr);
		if (*(src_ptr++) == (unsigned char)c) return dest;
	}
	return NULL;
}