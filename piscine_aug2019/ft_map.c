/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/20 12:01:19 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/20 19:21:14 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int lenght, int (*f)(int))
{
	int *arr;
	int count;

	arr = (int*)malloc(sizeof(int) * lenght);
	count = 0;
	while (count < lenght)
	{
		arr[count] = f(tab[count]);
		count++;
	}
	return (arr);
}
