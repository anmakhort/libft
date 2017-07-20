#include "libft.h"

void ft_memdel(void **ptr) {
	if (!ptr) return;
	free(*ptr);
	*ptr = NULL;
}