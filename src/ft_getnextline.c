#include "libft.h"

static t_list *global;

typedef struct content_s {
	int fd;
	char *buff;
	size_t buff_size;
} content_t;

content_t *_new(const int fd, char *buff, size_t size) {
	content_t *cont = \
		(content_t *)malloc(sizeof(content_t));
	if (!cont) return NULL;
	cont->fd = fd;
	cont->buff = buff;
	cont->buff_size = (!buff) ? 0 : size;
	return cont;
}

void _del(void *content, size_t sz) {
	sz = sz;
	if (!content || sz != sizeof(content_t)) return;
	if (((content_t *)content)->buff) \
		free(((content_t *)content)->buff);
	((content_t *)content)->buff = NULL;
	free(content);
	content = NULL;
}

ssize_t _read(t_list **head, const int fd) {
	if (!head || fd <= 0) return -1;
	t_list *ptr = *head;
	while (ptr->next && ((content_t*)(ptr->content))->fd != fd) \
		ptr = ptr->next;
	if (!ptr->next && ((content_t*)(ptr->content))->fd != fd) {
		content_t *content = _new(fd, NULL, 0);
		ptr->next = ft_lstnew(content, \
			sizeof(content_t));
		free(content);
		ptr = ptr->next;
		ptr->next = NULL;
	}
	char buff[DEFAULT_BUFF_SIZE+1] = {0};
	ssize_t n_read = 0;
	if ((n_read = read(fd, buff, DEFAULT_BUFF_SIZE)) > 0) {
		buff[n_read] = '\0';
		char *tmp = NULL;
		if (n_read == DEFAULT_BUFF_SIZE) \
			tmp = ft_strjoin(((content_t*)(ptr->content))->buff, buff);
		else {
			char *sub = ft_strsub(buff, 0, n_read);
			if (!sub) return -1;
			tmp = ft_strjoin(((content_t*)(ptr->content))->buff, sub);
			free(sub);
		}
		if (tmp) {
			free(((content_t*)(ptr->content))->buff);
			((content_t*)(ptr->content))->buff = tmp;
			((content_t*)(ptr->content))->buff_size += n_read;
		} else {
			return -1;
		}
	}
	return n_read;
}

char *_find(t_list **head, const char c, const int fd) {
	if (!head) return NULL;
	t_list *ptr = *head;
	char *sub = NULL;
	while (ptr) {
		if (!ptr->content) return NULL;
		if (((content_t*)(ptr->content))->fd == fd) break;
		ptr = ptr->next;
	}
	if (!(((content_t*)(ptr->content)))->buff_size) return NULL;
	size_t n = 0;
	char *ptr_str = (((content_t*)(ptr->content)))->buff;
	while (*ptr_str) {
		if (*ptr_str == c) break;
		n++;
		ptr_str++;
	}
	sub = ft_strsub((((content_t*)(ptr->content)))->buff, 0, n);
	if (sub) {
		char *tmp = ft_strsub(((content_t*)(ptr->content))->buff, \
			n+1, ((content_t*)(ptr->content))->buff_size-n-1);
		if (tmp) {
			free(((content_t*)(ptr->content))->buff);
			((content_t*)(ptr->content))->buff = tmp;
			((content_t*)(ptr->content))->buff_size -= n+1;
		} else {
			free(((content_t*)(ptr->content))->buff);
			((content_t*)(ptr->content))->buff = NULL;
			((content_t*)(ptr->content))->buff_size = 0;
		}
	}
	return sub;
}

char *ft_getnextline(const int fd) {
	if (!global) {
		content_t *content = _new(fd, NULL, 0);
		global = ft_lstnew(content, sizeof(content_t));
		free(content);
	}
	_read(&global, fd);
	char *line = _find(&global, '\n', fd);
	return line;
}

void ft_free_getnextline() {
	ft_lstdel(&global, _del);
}