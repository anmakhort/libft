#include "libft.h"

int ft_sign(int n) {
	return (n > 0 ? 1 : (n < 0 ? -1 : 0));
}