/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 11:56:14 by adimitri      #+#    #+#                 */
/*   Updated: 2020/02/05 14:09:40 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

t_list *ft_lstnew(void *content, void *content2)
{
	t_list	*new_node;

	new_node = NULL;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = (t_list *)malloc(sizeof(t_list));
	new_node->next->content = content2;
	new_node->next->next = NULL;
	return (new_node);
}

void del(void *head)
{
	char *temp;
	temp = ((char *)head);
	free(temp);
}

void	ft_lstdelone(t_list *lst, void (*del) (void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list *head;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst)
	{
		head = *lst;
		*lst = (*lst)->next;
		printf("hi\n");
		ft_lstdelone(head, (*del));
	}
	*lst = NULL;
}

int main(void)
{
	t_list *head;
	
	head = ft_lstnew("hello world", "this is C!");
	printf("before: %s\n", head->content);
	printf("second %s\n", head->next->content);
	
	ft_lstclear(&head, (*del));
	printf("\nafter: %s", head->content);
	return (0);
}
