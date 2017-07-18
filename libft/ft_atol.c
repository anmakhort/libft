#include "libft.h"

long ft_atol(const char *nptr) {
	if (!nptr) return ~0L;
	char *ptr = (char *)nptr;
	while (ft_isspace(*ptr)) ptr++;
	char sign = 0;
	if (*ptr == '-') {
		sign = 1;
		ptr++;
	}
	long n = 0L;
	while (ft_isdigit(*ptr)) {
		n = 10L * n + (long)(*ptr - '0');
		ptr++;
	}
	return (sign ? -n : n);
}