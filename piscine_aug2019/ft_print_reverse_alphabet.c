/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thewholecode.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/08 15:13:00 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/08 18:21:01 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	char i;

	i = 'z';
	while (i >= 'a')
	{
		ft_putchar(i);
		i = i - 1;
	}
}
