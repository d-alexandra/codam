/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nbrlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 18:08:10 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/25 18:13:22 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_nbrlen(int n)
{
	int count;

	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int main()
{
	int num;
	num = 3847748;

	printf("%d", ft_nbrlen(num));
	return(0);
}
