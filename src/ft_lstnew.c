#include "libft.h"

t_list *ft_lstnew(void const *content, size_t content_size) {
	t_list *new = (t_list *)malloc(sizeof(t_list));
	if (!new) return NULL;
	void *ptr = NULL;
	size_t sz = 0;
	if (content) {
		if (content_size) {
			ptr = malloc(content_size);
			if (!ptr) {
				free(new);
				return NULL;
			}
			ft_memcpy(ptr, content, content_size);
			sz = content_size;
		} else {
			free(new);
			return NULL;
		}
	}
	new->content = ptr;
	new->content_size = sz;
	new->next = NULL;
	return new;
}