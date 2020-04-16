/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:21:13 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 15:23:10 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_all	ft_has_min_str(t_formater begin, t_all f_spec, int min, int *count)
{
	if (min == 1 && begin.has_min > 0)
	{
		while (f_spec.bfr_min_afr > 0)
		{
			*count = *count + ft_putchar(' ');
			f_spec.bfr_min_afr--;
		}
	}
	if (min == -1 && begin.has_min <= 0)
	{
		while (f_spec.bfr_min_afr > 0)
		{
			*count = *count + ft_putchar(' ');
			f_spec.bfr_min_afr--;
		}
	}
	return (f_spec);
}
