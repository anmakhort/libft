#include "libft.h"

int ft_isxdigit(int c) {
	return (ft_isdigit(c) || \
		((c >= (int)'a') && (c <= (int)'f')) || \
		((c >= (int)'A') && (c <= (int)'F')));
}