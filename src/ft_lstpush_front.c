#include "../include/libft.h"

void ft_lstpush_front(t_list **alst, t_list *new) {
	ft_lstadd(alst, new);
}