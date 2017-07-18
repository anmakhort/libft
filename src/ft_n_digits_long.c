#include "libft.h"

size_t ft_n_digits_long(long number) {
	if (number == 0L) return 1;
	else if (number < 0L) return 1+ft_n_digits_int(-number);
	else {
		size_t n = 0;
		while (number) {
			n++;
			number /= 10L;
		}
		return n;
	}
}