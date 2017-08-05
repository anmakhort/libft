#include "../include/libft.h"

void ft_lstiter(t_list *lst, void (*f)(t_list *elem)) {
	if (!lst || !f) return;
	t_list *ptr = lst;
	while (ptr) {
		(*f)(ptr);
		ptr = ptr->next;
	}
}