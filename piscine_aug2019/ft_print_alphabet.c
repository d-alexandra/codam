/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   thewholecode.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/08 13:58:02 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/08 18:18:29 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_alphabet(void)
{
	char i;

	i = 'a';
	while (i <= 'z')
	{
		ft_putchar(i);
		i = i + 1;
	}
}
