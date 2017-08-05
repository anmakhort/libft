#include "../include/libft.h"

char *ft_readline(int fd, size_t buff_size) {
	char *buff = (char *)malloc(buff_size);
	if (!buff) {
		ft_putendl("Can't allocate memory!");
		return NULL;
	}
	ssize_t last_read = 0;
	size_t buff_offset = 0;
	size_t to_read = buff_size;
	while ((last_read = read(fd, buff+buff_offset, to_read)) > 0) {
		buff_offset += last_read;
		if ((size_t)last_read == to_read) { // need more size
			char *tmp = realloc(buff, buff_offset+buff_size);
			if (!tmp) {
				free(buff);
				return NULL;
			} else {
				buff = tmp;
			}
		}
	}
	char *tmp = realloc(buff, buff_offset);
	if (!tmp) {
		free(buff);
		return NULL;
	} else {
		buff = tmp;
	}
	return buff;
}