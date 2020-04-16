/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printptr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 17:09:28 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 14:57:07 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printptr_negative(t_formater begin, t_all f_spec, int *count)
{
	char	*ptrstr;

	f_spec.len = f_spec.after;
	if (ft_unbrlen(f_spec.ptr_to_prt) < f_spec.len)
		f_spec.len = ft_unbrlen(f_spec.ptr_to_prt);
	ptrstr = ft_itoa_base(f_spec.ptr_to_prt, 16, begin.type);
	write(1, "0x", 2);
	if (ptrstr)
	{
		while (f_spec.after > ft_strlen(ptrstr))
		{
			*count = *count + ft_putchar('0');
			f_spec.after--;
		}
	}
	ft_putstr(ptrstr);
	*count = *count + ft_strlen(ptrstr) + 2;
	f_spec = ft_putspaces(f_spec, count);
}

static void	ft_printptr_positive(t_formater begin, t_all f_spec, int *count)
{
	char	*ptrstr;

	if (begin.has_min <= 0)
		f_spec = ft_nomin_ptr(begin, f_spec, count);
	else
	{
		f_spec.len = 1;
		write(1, "0x", 2);
		*count = *count + 2;
		f_spec = ft_zero_uint(begin, f_spec, count);
	}
	if (f_spec.ptr_to_prt != 0 || f_spec.after != 0)
	{
		ptrstr = ft_itoa_base(f_spec.ptr_to_prt, 16, begin.type);
		if (!f_spec.len)
		{
			write(1, "0x", 2);
			*count = *count + 2;
		}
		ft_putstr(ptrstr);
		*count = *count + ft_strlen(ptrstr);
	}
	f_spec = ft_space_uint(begin, f_spec, count);
	f_spec = ft_putspaces(f_spec, count);
}

static void	ft_printptr_with_dot(t_formater begin, t_all f_spec, int *count)
{
	char	*ptrstr;
	int		nbrlen;

	f_spec = ft_check_dot(begin, f_spec);
	ptrstr = ft_itoa_base(f_spec.ptr_to_prt, 16, begin.type);
	if (f_spec.ptr_to_prt == 0 && f_spec.after == 0)
		nbrlen = 0;
	else
		nbrlen = ft_strlen(ptrstr);
	f_spec.total_len = f_spec.before - nbrlen;
	f_spec.bfr_min_afr = f_spec.before - f_spec.after;
	f_spec.spaces = f_spec.before - f_spec.after;
	if (nbrlen > f_spec.after)
		f_spec.spaces = f_spec.before - nbrlen;
	f_spec.spaces = ft_spacepad(f_spec, nbrlen) - 2;
	f_spec.zeroes = f_spec.after - nbrlen;
	if (f_spec.bfr_min_afr > 0)
		ft_printptr_positive(begin, f_spec, count);
	else
		ft_printptr_negative(begin, f_spec, count);
}

static void	ft_printptr_without_dot(t_formater begin, t_all f_spec, int *count)
{
	char	*ptrstr;

	ptrstr = ft_itoa_base(f_spec.ptr_to_prt, 16, begin.type);
	f_spec = ft_checkstar(begin, f_spec);
	if (begin.has_star < 0 || f_spec.bfr_star >= 0)
	{
		f_spec.len = f_spec.width - ft_strlen(ptrstr);
		f_spec = ft_ifmin_ptr(begin, f_spec, -1, count);
		write(1, "0x", 2);
		ft_putstr(ptrstr);
		*count = *count + ft_strlen(ptrstr) + 2;
		f_spec = ft_ifmin_ptr(begin, f_spec, 1, count);
	}
	else
	{
		write(1, "0x", 2);
		ft_putstr(ptrstr);
		*count = *count + ft_strlen(ptrstr) + 2;
		f_spec.len = f_spec.width * (-1) - ft_strlen(ptrstr) - 2;
		f_spec = ft_len(f_spec, count);
	}
}

void		ft_printptr(va_list list, t_formater begin, t_all f_spec,
int *count)
{
	f_spec.before = -1;
	f_spec.after = -1;
	f_spec.width = -1;
	if (begin.star_bfr_dot > 0)
		f_spec.bfr_star = va_arg(list, int);
	if (begin.star_afr_dot > 0)
		f_spec.afr_star = va_arg(list, int);
	f_spec.ptr_to_prt = va_arg(list, unsigned long);
	if (f_spec.ptr_to_prt == 0)
	{
		ft_putstr("0x");
		*count = *count + 2;
	}
	else
	{
		f_spec.bfr_min_afr = 0;
		f_spec.len = 0;
		if (begin.has_dot > 0)
			ft_printptr_with_dot(begin, f_spec, count);
		else
			ft_printptr_without_dot(begin, f_spec, count);
	}
}
