/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/14 17:41:59 by adimitri      #+#    #+#                 */
/*   Updated: 2019/08/14 21:11:35 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2);

int		ft_strcmp(char *s1, char *s2)
{
	int n;

	n = 0;
	while (s1[n] != '\0' && s2[n] != '\0')
	{
		if (s1[n] != s2[n])
			break ;
		n = n + 1;
	}
	return (s1[n] - s2[n]);
}
