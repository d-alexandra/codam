/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_size.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:58:03 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 15:02:33 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_all	ft_len(t_all f_spec, int *count)
{
	while (f_spec.len > 0)
	{
		*count = *count + ft_putchar(' ');
		f_spec.len--;
	}
	return (f_spec);
}

t_all	ft_min_wdot(t_formater begin, t_all f_spec, int nbrlen)
{
	if (begin.has_min > 0)
	{
		if (f_spec.after > nbrlen)
			f_spec.spaces = f_spec.before - f_spec.after;
		else
			f_spec.spaces = f_spec.before - nbrlen;
	}
	else
		f_spec.spaces = f_spec.before - f_spec.after;
	return (f_spec);
}

t_all	ft_ifmin_wdot(t_formater begin, t_all f_spec, int min, int *count)
{
	if (min == -1 && begin.has_min <= 0)
	{
		while (f_spec.len > 0)
		{
			ft_printintchr(begin, count);
			f_spec.len--;
		}
	}
	if (min == 1 && begin.has_min > 0)
		ft_len(f_spec, count);
	if (min == 2 && begin.has_min <= 0)
		ft_len(f_spec, count);
	return (f_spec);
}

t_all	ft_nomin_wdot(t_formater begin, t_all f_spec, int *count)
{
	if (begin.has_min <= 0)
	{
		while (f_spec.len > 0)
		{
			if (f_spec.int_to_prt < 0 && begin.has_zero > 0)
			{
				*count = *count + ft_putchar('-');
				f_spec.int_to_prt = f_spec.int_to_prt * (-1);
			}
			ft_printintchr(begin, count);
			f_spec.len--;
		}
	}
	return (f_spec);
}
