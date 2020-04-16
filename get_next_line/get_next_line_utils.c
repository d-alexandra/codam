/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/27 17:23:02 by adimitri      #+#    #+#                 */
/*   Updated: 2020/01/05 17:57:15 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char		*ft_strchr(const char *s, int c)
{
	int	len;
	int	count;
	char	*result;
	char	ch;

	count = 0;
	ch = (char)c;
	len = ft_strlen(s) + 1;
	while (count < len)
	{
		if (s[count] == ch)
		{
			result = (char *)&s[count];
			return (result);
		}
		count++;
	}
	return (0);
}

char		*ft_strdup(char *s1)
{
	int		src_size;
	int		count;
	char	*duplicate;

	src_size = 0;
	count = 0;
	while (s1[src_size] != '\0')
		src_size++;
	duplicate = (char *)malloc(sizeof(char) * (src_size + 1));
	if (!duplicate)
		return (NULL);
	while (count < src_size)
	{
		duplicate[count] = s1[count];
		count++;
	}
	duplicate[src_size] = '\0';
	return (duplicate);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int	index;
	int	count;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	count = 0;
	if (!new_str)
		return (NULL);
	while (s1[count] != '\0')
	{
		new_str[count] = s1[count];
		count++;
	}
	index = 0;
	while (s2[index] != '\0')
	{
		new_str[count] = s2[index];
		count++;
		index++;
	}
	new_str[count] = '\0';
	free(s1);
	return (new_str);
}

int		ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char		*ft_substr(char *s, unsigned int start, size_t len)
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
