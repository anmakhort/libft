#include "../include/libft.h"

int ft_strnequ(char const *s1, char const *s2, size_t n) {
	if (s1 == s2) return 1;
	else return (ft_strncmp(s1, s2, n) == 0);
}