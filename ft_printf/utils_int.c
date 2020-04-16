/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:23:27 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 16:29:26 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_all	ft_nomin_int(t_formater begin, t_all f_spec, int *count)
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
			else if (f_spec.int_to_prt < 0)
			{
				f_spec.int_to_prt = f_spec.int_to_prt * (-1);
				*count = *count + ft_putchar('-');
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

t_all	ft_zero_int(t_formater begin, t_all f_spec, int *count)
{
	if (begin.has_min > 0)
	{
		while (f_spec.zeroes > 0)
		{
			if (f_spec.int_to_prt < 0)
			{
				*count = *count + ft_putchar('-');
				f_spec.int_to_prt = f_spec.int_to_prt * (-1);
			}
			*count = *count + ft_putchar('0');
			f_spec.zeroes--;
			f_spec.total_len--;
		}
	}
	return (f_spec);
}

void	ft_int_to_prt(t_all f_spec, int *count)
{
	char	*itoastr;

	if (f_spec.int_to_prt != 0 || f_spec.after != 0)
	{
		if (f_spec.int_to_prt == -2147483648)
			ft_putstr("02147483648");
		else
		{
			itoastr = ft_itoa(f_spec.int_to_prt);
			*count = *count + ft_strlen(itoastr);
			ft_putstr(itoastr);
			free(itoastr);
		}
	}
}

int		ft_checknbrlen(t_formater begin, t_all f_spec)
{
	int	nbrlen;

	if (f_spec.int_to_prt == 0 && f_spec.after == 0)
		nbrlen = 0;
	else
		nbrlen = ft_nbrlen(f_spec.int_to_prt);
	if (f_spec.int_to_prt < 0 && begin.has_min < 0)
	{
		if (f_spec.before > 0 && f_spec.after >= nbrlen)
			nbrlen--;
	}
	return (nbrlen);
}
