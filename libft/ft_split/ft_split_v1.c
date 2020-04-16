/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 17:06:50 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/03 20:19:57 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static size_t		ft_wordcount(char const *s, char c)
{
	size_t	count;
	size_t	word;

	word = 0;
	while (*s != '\0')
	{
		if (s[count] != c)
			count++;
		else if (count > 0)
		{
			word++;
			count = 0;
		}
		s++;
	}
	if (count > 0)
		word++;
	return (word);
}

static size_t		ft_wordsize(char const *s, char c)
{
	size_t	size;
	size_t	count;

	size = 0;
	count = 0;	
	while (s[count] != 0)
	{
		count++;
		size++;
		if (s[count] == c)
			break ;
	}
	return (size);	
}

static void		ft_cleanmem(char **str)
{
	size_t count;

	count = 0;
	while ((*str)[count])
	{
		free(*str);
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
	while (word <= wcount)
	{
		while (*s == c)
			s++;
		wordsize = ft_wordsize(s, c);
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
		if (*s != c)
		{
			str[word][count] = *s;
			count++;
		}
		else if (count > 0)
		{
			str[word][count] = '\0';
			count = 0;
			word++;
		}
		s++;
	}
	str[word][count] = '\0';
	str[word + 1] = NULL;
	return (str);
}

int main()
{
	char *str = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	char **result = ft_split(str, ' ');
	size_t i;

	i = 0;
	while (result[i] != '\0')
	{
		printf("%s\n", result[i]);
		i++;
	}
	printf(".\n");
	return (0);
   Amsterdam    is     a     ciy}
