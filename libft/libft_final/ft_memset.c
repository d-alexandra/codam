/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 20:00:51 by adimitri      #+#    #+#                 */
/*   Updated: 2019/11/16 16:27:19 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ****************************************************************************/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			count;

	count = 0;
	str = (unsigned char *)b;
	while (count < len)
	{
		str[count] = (unsigned char)c;
		count++;
	}
	return (str);
}
