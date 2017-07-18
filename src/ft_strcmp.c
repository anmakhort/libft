#include "libft.h"

int ft_strcmp(const char *s1, const char *s2) {
	if (s1 == s2) return 0;
	size_t n1 = ft_strlen(s1), n2 = ft_strlen(s2);
	int res = ft_memcmp((const void*)s1, (const void*)s2, MIN(n1,n2));
	if (res == 0) return ft_sign(n1-n2);
	else return res;
}