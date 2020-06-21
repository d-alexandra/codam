/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thewholecode2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/08 16:01:36 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/08 18:33:04 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_numbers(void)
{
	char i;

	i = '0';
	while (i <= '9')
	{
		ft_putchar(i);
		i = i + 1;
	}
}
