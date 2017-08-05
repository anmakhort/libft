#include "../include/libft.h"

int ft_toupper(int c) {
	if (ft_islower(c)) return (c-((int)'a'-(int)'A'));
	else return c;
}