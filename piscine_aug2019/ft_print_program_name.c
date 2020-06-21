/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_params.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 22:38:22 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/16 11:59:38 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c);

int		main(int argc, char *argv[])
{
	int i;

	i = argc;
	if (argc > 0)
		while (argv[0][i] != '\0')
		{
			ft_putchar(argv[0][i]);
			i++;
		}
	return (0);
}
