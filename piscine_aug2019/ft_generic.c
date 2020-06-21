/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_generic.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 18:06:11 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/23 15:25:54 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_generic(void)
{
	char *c;

	c = "Tut tut ; Tut tut\n";
	write(1, c, 19);
}

int 	main()
{
	ft_generic();
	return (0);
}
