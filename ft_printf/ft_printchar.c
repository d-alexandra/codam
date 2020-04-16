/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printchar.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 15:58:01 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 13:50:44 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printchar_negative(t_formater begin, t_all f_spec, int *count)
{
	if (begin.type == '%')
		*count = *count + ft_putchar('%');
	else
		*count = *count + ft_putchar(f_spec.chr_to_prt);
	f_spec = ft_putspaces(f_spec, count);
}

static void	ft_printchar_positive(t_formater begin, t_all f_spec, int *count)
{
	if (begin.has_min <= 0)
	{
		while (f_spec.bfr_min_afr > 0)
		{
			*count = *count + ft_putchar(' ');
			f_spec.bfr_min_afr--;
		}
	}
	if (begin.type == '%')
		*count = *count + ft_putchar('%');
	else
		count = count + ft_putchar(f_spec.chr_to_prt);
	if (begin.has_min > 0)
	{
		while (f_spec.bfr_min_afr > 0)
		{
			*count = *count + ft_putchar(' ');
			f_spec.bfr_min_afr--;
		}
	}
	f_spec = ft_putspaces(f_spec, count);
}

static void	ft_printchar_with_dot(t_formater begin, t_all f_spec, int *count)
{
	f_spec = ft_check_dot(begin, f_spec);
	f_spec.bfr_min_afr = f_spec.before - 1;
	if (f_spec.before < 0)
		f_spec.spaces = f_spec.before * (-1) - 1;
	if (f_spec.bfr_min_afr > 0)
		ft_printchar_positive(begin, f_spec, count);
	else
		ft_printchar_negative(begin, f_spec, count);
}

static void	ft_printchar_without_dot(t_formater begin, t_all f_spec,
int *count)
{
	if (begin.has_star > 0)
		f_spec.width = f_spec.bfr_star;
	else
		f_spec.width = begin.width;
	f_spec.len = f_spec.width - 1;
	if (begin.has_star < 0 || f_spec.bfr_star >= 0)
	{
		f_spec = ft_ifmin_wdot(begin, f_spec, 2, count);
		if (begin.type == '%')
			*count = *count + ft_putchar('%');
		else
			*count = *count + ft_putchar(f_spec.chr_to_prt);
		f_spec = ft_ifmin_wdot(begin, f_spec, 1, count);
	}
	else
	{
		if (f_spec.chr_to_prt == '%')
			*count = *count + ft_putchar('%');
		else
			ft_putchar(f_spec.chr_to_prt);
		f_spec.len = f_spec.width * (-1) - 1;
		ft_len(f_spec, count);
	}
}

void		ft_printchar(va_list list, t_formater begin, t_all f_spec,
int *count)
{
	f_spec.before = -1;
	f_spec.after = -1;
	f_spec.width = -1;
	if (begin.star_bfr_dot > 0)
		f_spec.bfr_star = va_arg(list, int);
	if (begin.star_afr_dot > 0)
		f_spec.afr_star = va_arg(list, int);
	f_spec.chr_to_prt = va_arg(list, int);
	f_spec.bfr_min_afr = 0;
	f_spec.len = 0;
	if (begin.has_dot > 0)
		ft_printchar_with_dot(begin, f_spec, count);
	else
		ft_printchar_without_dot(begin, f_spec, count);
}
