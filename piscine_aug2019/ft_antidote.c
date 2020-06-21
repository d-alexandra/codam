/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_antidote.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 16:47:49 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/17 14:56:44 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_antidote(int i, int j, int k)
{
	if ((i > k && i < j) || (i < k && i > j))
		return (i);
	else if ((j > k && j < i) || (j < k && j > i))
		return (j);
	return (k);
}

int 	main(void)
{
	int c;

	c = ft_antidote(7, 7, 7);
	printf("%d", c);
	return (0);
}
