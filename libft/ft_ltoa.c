#include "libft.h"

char *ft_ltoa(long number) {
	size_t n_digits = ft_n_digits_long(number);
	char *str = ft_strnew(n_digits+1);
	if (!str) return NULL;
	if (number == 0L) {
		str[0] = '0';
		str[1] = '\0';
		return str;
	}
	if (number < 0L) {
		str[0] = '-';
		number = -number;
	}
	size_t idx = n_digits-1;
	while (number) {
		str[idx--] = (char)((number % 10L) + '0');
		number /= 10L;
	}
	str[n_digits] = '\0';
	return str;
}