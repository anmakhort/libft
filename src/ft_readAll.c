#include "../include/libft.h"

#ifdef BUFF_SIZE
	#if BUFF_SIZE < 1 || BUFF_SIZE > 4096
		#undef BUFF_SIZE
		#define BUFF_SIZE 128
	#endif
#else
	#define BUFF_SIZE 128
#endif

char *ft_readAll(int fd) {
	char buff[BUFF_SIZE] = {0};
	char *text = NULL;
	size_t length = 0;
	ssize_t last_read = 0;

	while ((last_read = read(fd, buff, BUFF_SIZE)) > 0) {
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