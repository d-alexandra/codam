/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 07:56:19 by adimitri      #+#    #+#                 */
/*   Updated: 2020/02/04 07:56:34 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*len;

	count = 0;
	if (!lst)
		return (0);
	len = lst;
	while (len != NULL)
	{
		count++;
		len = len->next;
	}
	return (count);
}
