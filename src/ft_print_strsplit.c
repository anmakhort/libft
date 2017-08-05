#include "../include/libft.h"

void ft_print_strsplit(char *** const s) {
	char **ptr = (char **)(*s);
	while (ptr && *ptr) \
		ft_putendl(*(ptr++));
}