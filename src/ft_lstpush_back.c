#include "../include/libft.h"

void ft_lstpush_back(t_list **alst, t_list *new) {
	if (!alst || !new) return;
	t_list *ptr = *alst;
	while (ptr->next) ptr = ptr->next;
	ptr->next = new;
	new->next = NULL;
}