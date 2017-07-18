#include "libft.h"

char *ft_strcat(char *dest, const char *src) {
	size_t dst_len = ft_strlen(dest);
	size_t n_copy = ft_strlen(src);
	char *ptr = ft_memmove(dest+dst_len, src, n_copy);
	if (ptr) {
		// ptr=dest+dst_len (if ft_memove succeeds) :
		ptr[n_copy] = '\0';
		return dest;
	}
	return NULL;
}