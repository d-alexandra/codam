/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_ptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:31:04 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 15:34:27 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_all	ft_nomin_ptr(t_formater begin, t_all f_spec, int *count)
{
	if (begin.has_min <= 0)
	{
		while (f_spec.total_len > 0)
		{
			if (f_spec.spaces > 0)
			{
				*count = *count + ft_putchar(' ');
				f_spec.spaces--;
			}
			else if (!f_spec.len)
			{
				f_spec.len = 1;
				write(1, "0x", 2);
				*count = *count + 2;
			}
			else if (f_spec.zeroes > 0)
			{
				*count = *count + ft_putchar('0');
				f_spec.zeroes--;
			}
			f_spec.total_len--;
		}
	}
	return (f_spec);
}

t_all	ft_ifmin_ptr(t_formater begin, t_all f_spec, int min, int *count)
{
	if (min == -1 && begin.has_min <= 0)
	{
		while (f_spec.len > 2)
		{
			ft_printintchr(begin, count);
			f_spec.len--;
		}
	}
	if (min == 1 && begin.has_min > 0)
	{
		while (f_spec.len > 2)
		{
			*count = *count + ft_putchar(' ');
			f_spec.len--;
		}
	}
	return (f_spec);
}
