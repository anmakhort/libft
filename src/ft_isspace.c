#include "../include/libft.h"

int ft_isspace(int c) {
	return ((c == (int)' ') || \
		(c == (int)'\f') || \
		(c == (int)'\t') || \
		(c == (int)'\n') || \
		(c == (int)'\r') || \
		(c == (int)'\v'));
}