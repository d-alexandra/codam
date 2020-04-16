/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strtrim.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 19:54:19 by adimitri      #+#    #+#                 */
/*   Updated: 2019/12/13 15:39:20 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char s, const char *set, int len)
{
	int		count;

	count = 0;
	while (count < len && set != 0)
	{
		if (s == set[count])
			return (1);
		count++;
	}
	return (0);
}

static int	ft_strstart(const char *s, const char *set, int len)
{
	int		start;
	int		countset;
	int		inset;

	start = 0;
	countset = ft_strlen(set);
	while (start < len && s != 0)
	{
		inset = ft_inset(s[start], set, countset);
		if (!inset)
			break ;
		else
			start++;
	}
	return (start);
}

static int	ft_strend(const char *s, const char *set, int len)
{
	int		end;
	int		countset;
	int		inset;

	end = len;
	countset = ft_strlen(set);
	while (end > 0)
	{
		inset = ft_inset(s[end - 1], set, countset);
		if (!inset)
			break ;
		else
			end--;
	}
	return (end);
}

char		*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	start = ft_strstart(s1, set, len);
	end = ft_strend(s1, set, len);
	return (ft_substr(s1, start, end - start));
}
