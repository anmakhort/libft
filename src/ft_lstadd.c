#include "libft.h"

void ft_lstadd(t_list **alst, t_list *new) {
	if (!alst || !new) return;
	//t_list *tmp = *alst;
	//*alst = new;
	//new->next = tmp;
	new->next = *alst;
	*alst = new;
}