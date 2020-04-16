/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printuint.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 14:34:33 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 14:42:28 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printuint_negative(t_all f_spec, int *count)
{
	char *itoastr;

	f_spec.len = f_spec.after;
	if (ft_nbrlen(f_spec.uint_to_prt) > f_spec.len)
		f_spec.len = ft_unbrlen(f_spec.uint_to_prt);
	else if (f_spec.len > ft_unbrlen(f_spec.uint_to_prt))
	{
		while (ft_unbrlen(f_spec.uint_to_prt) < f_spec.len)
		{
			*count = *count + ft_putchar('0');
			f_spec.len--;
		}
	}
	if (f_spec.uint_to_prt != 0 || f_spec.after != 0)
	{
		itoastr = ft_uitoa(f_spec.uint_to_prt);
		*count = *count + ft_strlen(itoastr);
		ft_putstr(itoastr);
		free(itoastr);
	}
	f_spec = ft_putspaces(f_spec, count);
}

static void	ft_printuint_positive(t_formater begin, t_all f_spec, int *count)
{
	char *itoastr;

	if (begin.has_min <= 0)
		f_spec = ft_nomin_uint(begin, f_spec, count);
	else
		f_spec = ft_zero_uint(begin, f_spec, count);
	f_spec.len = ft_unbrlen(f_spec.uint_to_prt);
	if (f_spec.uint_to_prt != 0 || f_spec.after != 0)
	{
		itoastr = ft_uitoa(f_spec.uint_to_prt);
		*count = *count + ft_strlen(itoastr);
		ft_putstr(itoastr);
		free(itoastr);
	}
	f_spec = ft_space_uint(begin, f_spec, count);
	f_spec = ft_putspaces(f_spec, count);
}

static void	ft_printuint_with_dot(t_formater begin, t_all f_spec, int *count)
{
	int nbrlen;

	f_spec = ft_check_dot(begin, f_spec);
	if (f_spec.uint_to_prt == 0 && f_spec.after == 0)
		nbrlen = 0;
	else
		nbrlen = ft_unbrlen(f_spec.uint_to_prt);
	f_spec.total_len = f_spec.before - nbrlen;
	f_spec.bfr_min_afr = f_spec.before - f_spec.after;
	if (f_spec.after > nbrlen)
		f_spec.spaces = f_spec.before - f_spec.after;
	else
		f_spec.spaces = f_spec.before - nbrlen;
	f_spec.spaces = ft_spacepad(f_spec, nbrlen);
	f_spec.zeroes = f_spec.after - nbrlen;
	if (f_spec.bfr_min_afr > 0)
		ft_printuint_positive(begin, f_spec, count);
	else
		ft_printuint_negative(f_spec, count);
}

static void	ft_printuint_without_dot(t_formater begin, t_all f_spec,
int *count)
{
	f_spec = ft_checkstar(begin, f_spec);
	if (begin.has_star < 0 || f_spec.bfr_star >= 0)
	{
		f_spec.len = f_spec.width - ft_unbrlen(f_spec.uint_to_prt);
		f_spec = ft_ifmin_wdot(begin, f_spec, -1, count);
		ft_putnbr_unsign(f_spec.uint_to_prt);
		*count = *count + ft_unbrlen(f_spec.uint_to_prt);
		f_spec = ft_ifmin_wdot(begin, f_spec, 1, count);
	}
	else
	{
		ft_putnbr_unsign(f_spec.uint_to_prt);
		*count = *count + ft_unbrlen(f_spec.uint_to_prt);
		f_spec.len = f_spec.width * (-1) - ft_unbrlen(f_spec.uint_to_prt);
		f_spec = ft_len(f_spec, count);
	}
}

void		ft_printuint(va_list list, t_formater begin, t_all f_spec,
int *count)
{
	f_spec.before = -1;
	f_spec.after = -1;
	f_spec.width = -1;
	if (begin.star_bfr_dot > 0)
		f_spec.bfr_star = va_arg(list, int);
	if (begin.star_afr_dot > 0)
		f_spec.afr_star = va_arg(list, int);
	f_spec.uint_to_prt = va_arg(list, unsigned int);
	f_spec.bfr_min_afr = 0;
	f_spec.len = 0;
	if (begin.has_dot > 0)
		ft_printuint_with_dot(begin, f_spec, count);
	else
		ft_printuint_without_dot(begin, f_spec, count);
}
