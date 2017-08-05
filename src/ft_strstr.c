#include "../include/libft.h"

char *ft_strstr(const char *haystack, const char *needle) {
	if (!haystack || !needle) return NULL;
	size_t sz = ft_strlen(needle);
	if (sz == 0) return NULL;
	else if (sz == 1) return ft_strchr(haystack, needle[0]);
	else {
		char *ptr = ft_strchr(haystack, needle[0]);
		while (ptr) {
			size_t i = 1;
			while (i < sz) {
				if (ptr[i] != needle[i]) break;
				i++; // 'i' will be equal to 'sz' if needle was found
			}
			if (i == sz) { // entry was found!
				return ptr;
			} else { // else -> try again
				ptr = ft_strchr(ptr+i, needle[0]);
			}
		}
	}
	return NULL;
}