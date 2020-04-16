/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 17:06:50 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/05 18:19:48 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(const char *s, char c)
{
	size_t		word;

	word = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != 0)
			s++;
		if (*s != c && *s != 0)
			word++;
		while (*s != c && *s != 0)
			s++;
	}
	return (word);
}

static size_t	ft_wordsize(const char *s, char c)
{
	size_t		size;

	size = 0;
	while (*s != 0)
	{
		s++;
		size++;
		if (*s == c)
			break ;
	}
	return (size);
}

static char		**ft_cleanmem(char **str)
{
	size_t		count;

	count = 0;
	while (str[count])
	{
		free(str[count]);
		count++;
	}
	free(str);
	return (NULL);
}

static char		**ft_allocmem(const char *s, char c)
{
	char		**str;
	size_t		word;
	size_t		wcount;

	if (!s)
		return (NULL);
	wcount = ft_wordcount(s, c);
	str = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!str)
		return (NULL);
	word = 0;
	while (word < wcount)
	{
		while (*s == c)
			s++;
		str[word] = (char *)malloc(sizeof(char) * (ft_wordsize(s, c) + 1));
		if (!str[word])
			return (ft_cleanmem(str));
		while (*s != c && *s != 0)
			s++;
		word++;
	}
	str[wcount] = 0;
	return (str);
}

char			**ft_split(const char *s, char c)
{
	char		**str;
	size_t		count;
	size_t		word;

	str = ft_allocmem(s, c);
	if (!str)
		return (NULL);
	word = 0;
	while (*s != '\0')
	{
		count = 0;
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		while (*s != c && *s != 0)
		{
			str[word][count] = *s;
			count++;
			s++;
		}
		str[word][count] = '\0';
		word++;
	}
	return (str);
}
