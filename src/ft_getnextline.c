#include "../include/libft.h"

#ifdef BUFF_SIZE
	#if BUFF_SIZE < 1 || BUFF_SIZE > 4096
		#undef BUFF_SIZE
		#define BUFF_SIZE 32
	#endif
#else
	#define BUFF_SIZE 32
#endif


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
	char buff[BUFF_SIZE+1] = {0};
	ssize_t n_read = 0;
	if ((n_read = read(fd, buff, BUFF_SIZE)) > 0) {
		buff[n_read] = '\0';
		char *tmp = NULL;
		if (n_read == BUFF_SIZE) \
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
	while (ptr) {
		if (!ptr->content) return NULL;
		if (((content_t*)(ptr->content))->fd == fd) break;
		ptr = ptr->next;
	}
	if (!(((content_t*)(ptr->content)))->buff_size) return NULL;
	// try to read while '\n' not found:
	char *buff_ptr = (((content_t*)(ptr->content)))->buff;
	char *ptr_found = NULL;
	size_t offset = 0;
	while ((ptr_found = ft_strchr(buff_ptr+offset, c)) == NULL) {
		ssize_t n_read = _read(head, fd);
		if (n_read <= 0) break;
		offset += n_read;
		// update the poiter as it was reallocated by _read(...)
		// function -> its address might change after
		// the call of _read(...) :
		buff_ptr = (((content_t*)(ptr->content)))->buff;
	}
	size_t n = (!ptr_found) ? 0 : (size_t)(ptr_found - buff_ptr);
	// for this moment we have the index of first '\n' char
	// or n = 0 if it wasn't found (even if we reached EOF)
	// strsub with zero size will return NULL:
	char *sub = ft_strsub((((content_t*)(ptr->content)))->buff, 0, n);
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