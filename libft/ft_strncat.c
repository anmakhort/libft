#include "libft.h"

char *ft_strncat(char *dest, const char *src, size_t n) {
	size_t n_copy = MIN(n,ft_strlen(src));
	size_t dst_len = ft_strlen(dest);
	char *ptr = ft_memmove(dest+dst_len, src, n_copy);
	if (ptr) {
		// ptr=dest+dst_len (if ft_memmove succeeds) :
		ptr[n_copy] = '\0';
		return dest;
	}
	return NULL;
}