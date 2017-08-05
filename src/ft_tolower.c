#include "../include/libft.h"

int ft_tolower(int c) {
	if (ft_isupper(c)) return (c+((int)'a'-(int)'A'));
	else return c;
}