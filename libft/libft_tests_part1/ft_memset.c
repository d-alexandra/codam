/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 20:00:51 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/09 18:39:39 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ****************************************************************************/

#include <stdio.h>
#include <string.h>

void *ft_memset(void *s, int c, size_t n)
{
	char *str;
	size_t count;

	count = 0;
	str = (char *)s;
	while (count < n)
	{
		str[count] = (char)c;
		count++;
	}
	return (str);
}

int main()
{
	char str[30]= "Sentences with numbers";
	
	printf("%s", ft_memset(str,'@', 7));
	return (0);
}
