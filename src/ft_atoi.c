#include "../include/libft.h"

int ft_atoi(const char *nptr) {
	if (!nptr) return ~0;
	char *ptr = (char *)nptr;
	while (ft_isspace(*ptr)) ptr++;
	char sign = 0;
	if (*ptr == '-') {
		sign = 1;
		ptr++;
	}
	int n = 0;
	while (ft_isdigit(*ptr)) {
		n = 10 * n + (int)(*ptr - '0');
		ptr++;
	}
	return (sign ? -n : n);
}