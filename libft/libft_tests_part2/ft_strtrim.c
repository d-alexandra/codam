/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strtrim.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 19:54:19 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/01 16:42:59 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int		ft_inset(char s, const char *set, int len);
char	*ft_reverstr(char const *s, char *str);


char *ft_strtrim(char const *s1, char const *set)
{
	int len;
	char *str;
	char *strhelper;

	len = strlen(set);
	if (!s1)
		return (NULL);
	while (ft_inset(*s1, set, len))
		s1++;
	strhelper = (char *)malloc(sizeof(char) * strlen(s1) + 1);
	printf("%s\n", s1); //without the trim at the back
	str = ft_reverstr(s1, strhelper);
	if (!strhelper)
		return (NULL);
	while (ft_inset(*str, set, len))
		str++;
	strhelper = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!strhelper)
		return (NULL);
	else
		return (ft_reverstr(str));
}

int ft_inset(char s, const char *set, int len)
{
	int count;

	count = 0;
	while (count < len)
	{
		if (s == set[count])
			return (1);
		count++;
	}
	return (0);
}

char *ft_reverstr(char const *s, char *str)
{
	int count;
	int len;

	if (!str)
		return (NULL);
	count = 0;
	len = strlen(s) - 1;
	while (len >= 0)
	{
		str[count] = s[len];
		count++;
		len--;
	}
	str[count] = '\0';
	return(str);
}

int main()
{
	char *arr = "  ++ Amsterdam  --  ";
	printf("%s\n", arr);

	char *set = " + -  ";
	char *new = ft_strtrim(arr, set);
	printf("%s\n", new);
	return (0);
}
