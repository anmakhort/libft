#include "../include/libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n) {
	if (s1 == s2) return 0;
	if (s1 && !s2) return 1;
	if (!s1 && s2) return -1;
	unsigned char *ptr1 = (unsigned char *)s1;
	unsigned char *ptr2 = (unsigned char *)s2;
	while (n--) {
		int diff = (int)(*ptr1++)-(int)(*ptr2++);
		if (diff != 0) return diff;
	}
	return 0;
}