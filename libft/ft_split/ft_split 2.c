/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 17:06:50 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/03 17:39:10 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static size_t		ft_wordcount(char const *s, char c)
{
	size_t	word;

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

static size_t		word_size(char const *s, char c)
{
	size_t 		size;

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

static void		ft_cleanmem(char **str)
{
	size_t count;

	count = 0;
	while (str[count])
	{
		free(str[count]);
		count++;
	}
	free(str);
}

static char			**ft_allocmem(char const *s, char c)
{
	char	**str;
	size_t	wcount;
	size_t	word;
	size_t	wordsize;
	
	wcount = ft_wordcount(s, c);
	str = (char **)malloc(sizeof(char *) * (wcount + 1));
	str[wcount] = 0;
	word = 0;
	while (word < wcount)
	{
		while (*s == c)
			s++;
		wordsize = word_size(s, c);
		str[word] = (char *)malloc(sizeof(char *) * (wordsize + 1));
		if (str[word] == NULL)
		{
			ft_cleanmem(str);
			return (NULL);
		}
		while (*s != c)
			s++;
		word++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t 	count;
	size_t	word;

	str = ft_allocmem(s, c);
	count = 0;
	word = 0;

	while (*s != '\0')
	{
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
		count = 0;
		word++;
	}
	str[word] = NULL;
	return (str);
}

int main()
{
	char *str = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	char **result = ft_split(str, ' ');
	size_t i;

	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i]);
		i++;
	}
	return (0);
}
