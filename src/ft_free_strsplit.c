#include "libft.h"

void ft_free_strsplit(char *** const s) {
	if (!s || !(*s)) return;
	char **ptr = (char **)(*s);
	while (ptr && *ptr) free(*(ptr++));
	free(*s);
	ptr =  NULL;
}