#include "libft.h"

char *ft_readAll(int fd) {
	char buff[DEFAULT_BUFF_SIZE] = {0};
	char *text = NULL;
	size_t length = 0;
	ssize_t last_read = 0;

	while ((last_read = read(fd, buff, DEFAULT_BUFF_SIZE)) > 0) {
		if (text) {
			REALLOC_SAFE(text, length+last_read+1)
		} else {
			text = (char *)malloc(last_read+1);
			if (!text) return NULL;
		}
		ft_memcpy(text+length, buff, last_read);
		length += last_read;
		text[length] = '\0';
	}
	return text;
}