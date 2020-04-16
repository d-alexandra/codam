/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_uint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:28:54 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 15:30:46 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_all	ft_nomin_uint(t_formater begin, t_all f_spec, int *count)
{
	if (begin.has_min <= 0)
	{
		while (f_spec.total_len > 0)
		{
			if (f_spec.spaces > 0)
			{
				*count = *count + ft_putchar(' ');
				f_spec.spaces--;
				f_spec.total_len--;
			}
			else if (f_spec.zeroes > 0)
			{
				*count = *count + ft_putchar('0');
				f_spec.zeroes--;
				f_spec.total_len--;
			}
		}
	}
	return (f_spec);
}

t_all	ft_zero_uint(t_formater begin, t_all f_spec, int *count)
{
	if (begin.has_min > 0)
	{
		while (f_spec.zeroes > 0)
		{
			*count = *count + ft_putchar('0');
			f_spec.zeroes--;
			f_spec.total_len--;
		}
	}
	return (f_spec);
}

t_all	ft_space_uint(t_formater begin, t_all f_spec, int *count)
{
	if (begin.has_min > 0)
	{
		while (f_spec.spaces > 0)
		{
			*count = *count + ft_putchar(' ');
			f_spec.spaces--;
			f_spec.total_len--;
		}
	}
	return (f_spec);
}
