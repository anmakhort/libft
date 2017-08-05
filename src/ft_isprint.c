#include "../include/libft.h"

int ft_isprint(int c) {
	return ((c >= (int)' ') && (c < 0x80));
}