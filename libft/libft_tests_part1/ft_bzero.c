/* ****************************************************************************/
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 21:11:21 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/09 18:41:30 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

void ft_bzero(void *s, size_t n)
{
	char *str;
	size_t count;

	str = (char *)s;
	count = 0;
	while(count < n)
	{
		str[count] = '\0';
		count++;
	}	
}

int main()
{
	char str[30]  = "months of the year";
	
	ft_bzero(str, 5);
	printf("%s", str + 5);
	return (0);
}
