#include "libft.h"

void ft_lstdel(t_list **alst, void (*del)(void *, size_t)) {
	if (!alst || !del) return;
	t_list *ptr = *alst;
	while (ptr) {
		t_list *tmp = ptr->next;
		(*del)(ptr->content, ptr->content_size);
		ptr->content = NULL;
		free(ptr);
		ptr = tmp;
	}
	*alst = NULL;
}