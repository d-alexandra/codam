/* ****************************************************************************/
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 21:11:21 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/16 14:06:21 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
