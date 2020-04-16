#include <stdio.h>
#include "libft.h"

t_list	*ft_lstnew(void	*content, void *content2)
{
	t_list *new_node;

	new_node = NULL;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = (t_list *)malloc(sizeof(t_list));
	new_node->next->next = NULL;
	new_node->next->content = content2;
	return (new_node);
}

t_list *ft_lstlast(t_list *lst)
{
	t_list *last_node;
	if (!lst)
		return (NULL);
	
	last_node = lst;
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}

int main(void)
{
	t_list *head;
	head = ft_lstnew("hello world", "i'm C!\n");
	head = ft_lstlast(head);
	printf("%s", head->content);
	return (0);
}

