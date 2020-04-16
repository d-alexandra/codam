/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:15:08 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 15:16:47 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	count;

	str = (char *)s;
	count = 0;
	while (count < n)
	{
		str[count] = '\0';
		count++;
	}
}

void	ft_printintchr(t_formater begin, int *count)
{
	if (begin.has_zero > 0)
		*count = *count + ft_putchar('0');
	else
		*count = *count + ft_putchar(' ');
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (slen - start < len)
		len = slen - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	index = 0;
	while (s[start] != '\0' && index < len)
	{
		str[index] = s[start];
		start++;
		index++;
	}
	str[index] = '\0';
	return (str);
}
