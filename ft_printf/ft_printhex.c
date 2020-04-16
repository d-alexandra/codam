/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printhex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/24 14:44:00 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 14:49:52 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printhex_negative(t_formater begin, t_all f_spec, int *count)
{
	char	*hexstr;
	int		nbrlen;

	f_spec.len = f_spec.after;
	hexstr = ft_itoa_base(f_spec.hex_to_prt, 16, begin.type);
	nbrlen = ft_strlen(hexstr);
	if (nbrlen > f_spec.len)
		f_spec.len = nbrlen;
	while (f_spec.len > nbrlen)
	{
		*count = *count + ft_putchar('0');
		f_spec.len--;
	}
	if (f_spec.hex_to_prt != 0 || f_spec.after != 0)
	{
		*count = *count + ft_strlen(hexstr);
		ft_putstr(hexstr);
	}
	f_spec = ft_putspaces(f_spec, count);
}

static void	ft_printhex_positive(t_formater begin, t_all f_spec, int *count)
{
	char *hexstr;

	if (begin.has_min <= 0)
		f_spec = ft_nomin_uint(begin, f_spec, count);
	else
		f_spec = ft_zero_uint(begin, f_spec, count);
	if (f_spec.hex_to_prt != 0 || f_spec.after != 0)
	{
		hexstr = ft_itoa_base(f_spec.hex_to_prt, 16, begin.type);
		*count = *count + ft_strlen(hexstr);
		ft_putstr(hexstr);
	}
	if (begin.has_min > 0)
	{
		while (f_spec.total_len > 0)
		{
			if (f_spec.spaces > 0)
			{
				*count = *count + ft_putchar(' ');
				f_spec.spaces--;
			}
			f_spec.total_len--;
		}
	}
	f_spec = ft_putspaces(f_spec, count);
}

static void	ft_printhex_with_dot(t_formater begin, t_all f_spec, int *count)
{
	int		nbrlen;
	char	*hexstr;

	f_spec = ft_check_dot(begin, f_spec);
	hexstr = ft_itoa_base(f_spec.hex_to_prt, 16, begin.type);
	if (f_spec.hex_to_prt == 0 && f_spec.after == 0)
		nbrlen = 0;
	else
		nbrlen = ft_strlen(hexstr);
	f_spec.total_len = f_spec.before - nbrlen;
	f_spec.bfr_min_afr = f_spec.before - f_spec.after;
	if (f_spec.after > nbrlen)
		f_spec.spaces = f_spec.before - f_spec.after;
	else
		f_spec.spaces = f_spec.before - nbrlen;
	f_spec.spaces = ft_spacepad(f_spec, nbrlen);
	f_spec.zeroes = f_spec.after - nbrlen;
	if (f_spec.bfr_min_afr > 0)
		ft_printhex_positive(begin, f_spec, count);
	else
		ft_printhex_negative(begin, f_spec, count);
}

static void	ft_printhex_without_dot(t_formater begin, t_all f_spec, int *count)
{
	char	*hexstr;

	hexstr = ft_itoa_base(f_spec.hex_to_prt, 16, begin.type);
	f_spec = ft_checkstar(begin, f_spec);
	if (begin.has_star < 0 || f_spec.bfr_star >= 0)
	{
		f_spec.len = f_spec.width - ft_strlen(hexstr);
		f_spec = ft_nomin_wdot(begin, f_spec, count);
		if (begin.has_min <= 0)
			*count = *count + ft_putchar(' ');
		*count = *count + ft_strlen(hexstr);
		ft_putstr(hexstr);
		if (begin.has_min > 0)
			*count = *count + ft_putchar(' ');
		f_spec = ft_len(f_spec, count);
	}
	else
	{
		ft_putstr(hexstr);
		*count = *count + ft_strlen(hexstr);
		f_spec.len = f_spec.width * (-1) - ft_strlen(hexstr);
		f_spec = ft_len(f_spec, count);
	}
}

void		ft_printhex(va_list list, t_formater begin, t_all f_spec,
int *count)
{
	f_spec.before = -1;
	f_spec.after = -1;
	f_spec.width = -1;
	if (begin.star_bfr_dot > 0)
		f_spec.bfr_star = va_arg(list, int);
	if (begin.star_afr_dot > 0)
		f_spec.afr_star = va_arg(list, int);
	f_spec.hex_to_prt = va_arg(list, unsigned int);
	f_spec.bfr_min_afr = 0;
	f_spec.len = 0;
	if (begin.has_dot > 0)
		ft_printhex_with_dot(begin, f_spec, count);
	else
		ft_printhex_without_dot(begin, f_spec, count);
}
