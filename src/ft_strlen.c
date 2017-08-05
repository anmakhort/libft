#include "../include/libft.h"

size_t ft_strlen(const char *s) {
	if (!s) return 0;
	char *ptr = (char *)s;
	size_t len = 0;
	while (*ptr) {
		len++;
		ptr++;
	}
	return len;
}