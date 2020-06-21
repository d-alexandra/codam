/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_foreach.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:25:27 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/19 19:55:12 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int lenght, void (*f)(int))
{
	int count;

	count = 0;
	while (count < lenght)
	{
		f(tab[count]);
		count++;
	}
}
