#include "../include/libft.h"

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem)) {
	if (!lst || !f) return NULL;
	t_list *new = NULL;
	t_list *ptr = lst;
	t_list *ptr_new = NULL;
	while (ptr) {
		if (!new) { // first time -> create list:
			new = (*f)(ptr);
			new->next = NULL;
			ptr_new = new;
		} else {
			ptr_new->next = (*f)(ptr);
			ptr_new = ptr_new->next;
		}
		ptr = ptr->next;
	}
	return new;
}