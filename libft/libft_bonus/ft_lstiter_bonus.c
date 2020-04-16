#include <stdio.h>
#include "libft.h"

void 	ft_printnbr(void *nbr)
{
	printf("%d", *((int *)nbr));
}

void ft_lstiter(t_list *lst, void (*f) (void *))
{
	while (lst != NULL)
	{
		if (lst->content != NULL)
			f (lst->content);
		lst = lst->next;
	}
}

t_list *ft_lstnew(void *content, void *content2)
{	
	t_list	*new_node;

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

int main(void)
{
	t_list *head;
	int val = 10;
	int val2 = 20;

	int *ptr = &val;
	int *ptr2 = &val2;

	head = ft_lstnew(ptr, ptr2);
	ft_lstiter(head, ft_printnbr);
	return (0);
}
