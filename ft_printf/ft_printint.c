/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printint.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/15 18:03:24 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 14:33:45 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_all	ft_int_count(t_formater begin, t_all f_spec)
{
	int			nbrlen;

	nbrlen = ft_nbrlen(f_spec.int_to_prt) - f_spec.bfr_min_afr;
	f_spec.zeroes = 0;
	if (f_spec.after > nbrlen)
		f_spec.zeroes = f_spec.after - nbrlen;
	f_spec.len = nbrlen + f_spec.zeroes + f_spec.bfr_min_afr;
	if (f_spec.before < 0)
	{
		f_spec.before = (-1) * f_spec.before;
		f_spec.str_is_null = 1;
	}
	if (begin.has_min > 0 || f_spec.str_is_null)
		f_spec.afr_star = f_spec.before - f_spec.len;
	else
		f_spec.spaces = f_spec.before - f_spec.len;
	if (begin.has_zero > 0 && begin.has_min < 0 && f_spec.after < 0)
	{
		f_spec.zeroes = f_spec.spaces;
		f_spec.spaces--;
	}
	return (f_spec);
}

static void		ft_int_print(t_all f_spec, int *count)
{
	while (f_spec.spaces > 0)
	{
		*count = *count + ft_putchar(' ');
		f_spec.spaces--;
	}
	if (f_spec.bfr_min_afr == 1)
		*count = *count + ft_putchar('-');
	while (f_spec.zeroes > 0)
	{
		*count = *count + ft_putchar('0');
		f_spec.zeroes--;
	}
	if (f_spec.int_to_prt < 0)
		f_spec.int_to_prt = (-1) * f_spec.int_to_prt;
	if (f_spec.int_to_prt == -2147483648)
		ft_putstr("-2147483648");
	else if (f_spec.int_to_prt == 0 && f_spec.after == 0)
		*count = *count + ft_putchar(' ');
	else
		ft_putnbr(f_spec.int_to_prt);
	while (f_spec.afr_star > 0)
	{
		*count = *count + ft_putchar(' ');
		f_spec.afr_star--;
	}
}

static void	ft_printint_with_dot(t_formater begin, t_all f_spec, int *count)
{
	f_spec = ft_check_dot(begin, f_spec);
	f_spec.str_is_null = 0;
	f_spec.spaces = 0;
	f_spec.afr_star = 0;
	f_spec.bfr_min_afr = 0;
	if (f_spec.int_to_prt < 0)
		f_spec.bfr_min_afr = 1;
	f_spec = ft_int_count(begin, f_spec);
	ft_int_print(f_spec, count);
	if (f_spec.int_to_prt == -2147483648)
		*count = *count + 10;
	else
		*count = *count + ft_nbrlen(f_spec.int_to_prt);
}

static void	ft_printint_without_dot(t_formater begin, t_all f_spec, int *count)
{
	f_spec = ft_checkstar(begin, f_spec);
	if (begin.has_star < 0 || f_spec.bfr_star >= 0)
	{
		f_spec.len = f_spec.width - ft_nbrlen(f_spec.int_to_prt);
		f_spec = ft_nomin_wdot(begin, f_spec, count);
		ft_putnbr(f_spec.int_to_prt);
		*count = *count + ft_nbrlen(f_spec.int_to_prt);
		f_spec = ft_ifmin_wdot(begin, f_spec, 1, count);
	}
	else
	{
		ft_putnbr(f_spec.int_to_prt);
		f_spec.len = f_spec.width * (-1) - ft_nbrlen(f_spec.int_to_prt);
		f_spec = ft_len(f_spec, count);
	}
}

void		ft_printint(va_list list, t_formater begin, t_all f_spec,
int *count)
{
	f_spec.before = -1;
	f_spec.after = -1;
	f_spec.width = -1;
	f_spec.spaces = -1;
	f_spec.zeroes = -1;
	f_spec.total_len = -1;
	if (begin.star_bfr_dot > 0)
		f_spec.bfr_star = va_arg(list, int);
	if (begin.star_afr_dot > 0)
		f_spec.afr_star = va_arg(list, int);
	f_spec.int_to_prt = va_arg(list, int);
	f_spec.bfr_min_afr = 0;
	f_spec.len = 0;
	if (begin.has_dot > 0)
		ft_printint_with_dot(begin, f_spec, count);
	else
		ft_printint_without_dot(begin, f_spec, count);
}
