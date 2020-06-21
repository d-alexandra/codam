/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 13:56:23 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/14 21:09:04 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		count = count + 1;
	}
	return (count);
}
