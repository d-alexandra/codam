/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/15 16:28:57 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/07 14:46:11 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_all	ft_str_count(t_formater begin, t_all f_spec)
{
	int		strlen;

	strlen = ft_strlen(f_spec.str_to_prt);
	f_spec.len = strlen;
	if (f_spec.after >= 0)
		f_spec.len = f_spec.after;
	if (f_spec.after >= strlen)
		f_spec.len = strlen;
	if (f_spec.before < 0)
	{
		f_spec.before = f_spec.before * (-1);
		f_spec.total_len = 1;
	}
	if (begin.has_min > 0 || f_spec.total_len)
		f_spec.afr_star = f_spec.before - f_spec.len;
	else
		f_spec.spaces = f_spec.before - f_spec.len;
	return (f_spec);
}

static t_all	ft_str_print(t_all f_spec, int *count)
{
	char *substr;

	while (f_spec.spaces > 0)
	{
		*count = *count + ft_putchar(' ');
		f_spec.spaces--;
	}
	substr = ft_substr(f_spec.str_to_prt, 0, f_spec.len);
	if (substr)
	{
		*count = *count + ft_strlen(substr);
		ft_putstr(substr);
		free(substr);
	}
	while (f_spec.afr_star > 0)
	{
		*count = *count + ft_putchar(' ');
		f_spec.afr_star--;
	}
	return (f_spec);
}

static void	ft_printstr_with_dot(t_formater begin, t_all f_spec, int *count)
{
	f_spec = ft_check_dot(begin, f_spec);
	f_spec.total_len = 0;
	f_spec.afr_star = 0;
	f_spec.spaces = 0;
	f_spec = ft_str_count(begin, f_spec);
	f_spec = ft_str_print(f_spec, count);
}

static void	ft_printstr_without_dot(t_formater begin, t_all f_spec, int *count)
{
	f_spec = ft_checkstar(begin, f_spec);
	if (begin.has_star < 0 || f_spec.bfr_star >= 0)
	{
		f_spec.len = f_spec.width - ft_strlen(f_spec.str_to_prt);
		if (begin.has_min <= 0)
			ft_len(f_spec, count);
		ft_putstr(f_spec.str_to_prt);
		*count = *count + ft_strlen((f_spec.str_to_prt));
		f_spec = ft_ifmin_wdot(begin, f_spec, 1, count);
	}
	else
	{
		ft_putstr(f_spec.str_to_prt);
		*count = *count + ft_strlen((f_spec.str_to_prt));
		f_spec.len = f_spec.width * (-1) - ft_strlen(f_spec.str_to_prt);
		ft_len(f_spec, count);
	}
}

void		ft_printstr(va_list list, t_formater begin, t_all f_spec,
int *count)
{
	f_spec.before = -1;
	f_spec.after = -1;
	f_spec.width = -1;
	f_spec.str_is_null = 0;
	if (begin.star_bfr_dot > 0)
		f_spec.bfr_star = va_arg(list, int);
	if (begin.star_afr_dot > 0)
		f_spec.afr_star = va_arg(list, int);
	f_spec.str_to_prt = va_arg(list, char *);
	if (f_spec.str_to_prt == NULL)
	{
		f_spec.str_to_prt = "(null)";
		f_spec.str_is_null = 1;
		*count = *count + 6;
	}
	f_spec.bfr_min_afr = 0;
	f_spec.len = 0;
	if (begin.has_dot > 0)
		ft_printstr_with_dot(begin, f_spec, count);
	else
		ft_printstr_without_dot(begin, f_spec, count);
}
