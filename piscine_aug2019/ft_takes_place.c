/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_takes_place.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 20:00:07 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/17 14:26:37 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_takes_place(int hour)
{
	int		before;
	int		after;
	char	*b;
	char	*a;

	before = 12;
	after = 1;
	b = (hour >= 12) ? "PM" : "AM";
	a = (hour >= 11) ? "PM" : "AM";
	a = (hour == 23 || hour == 24) ? "AM" : a;
	b = (hour == 0 || hour == 24) ? "AM" : b;
	before = hour % 12;
	after = before + 1;
	before = (before == 0) ? 12 : before;
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%d.00%s AND %d.00%s\n", before, b, after, a);
}

int		main(void)
{
	int i;

	i = 0;
	while (i < 24)
	{
		ft_takes_place(i);
		i++;
	}
	return (0);
}	
