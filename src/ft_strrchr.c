#include "../include/libft.h"

char *ft_strrchr(const char *s, int c) {
	if (!s) return NULL;
	char *ptr = (char *)s;
	char *last = NULL;
	while (*ptr) {
		if (*ptr == c) last = ptr;
		ptr++;
	}
	return last;
}