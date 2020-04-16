/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone_bonus.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 11:56:14 by adimitri      #+#    #+#                 */
/*   Updated: 2020/02/05 13:54:40 by adimitri      ########   odam.nl         */
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

void	del(void *head)
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

int main(void)
{
	t_list *head;

	head = ft_lstnew(ft_strdup("hello world"), "this is C!");
	printf("before: %s", head->content);
	
	ft_lstdelone(head, (*del));
	printf("\nafter: %s", head->content);
	return (0);
}
