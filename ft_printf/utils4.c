/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils4.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/06 15:17:05 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 16:28:46 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_spacepad(t_all f_spec, int nbrlen)
{
	int spacepad;

	spacepad = f_spec.spaces;
	if (f_spec.before < 0 && f_spec.after <= 0)
		spacepad = f_spec.before * (-1) - nbrlen;
	return (spacepad);
}

t_all	ft_putspaces(t_all f_spec, int *count)
{
	if (f_spec.before < 0)
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

t_all	ft_check_dot(t_formater begin, t_all f_spec)
{
	if (begin.star_bfr_dot > 0)
		f_spec.before = f_spec.bfr_star;
	else
		f_spec.before = begin.bfr_dot;
	if (begin.star_afr_dot > 0)
		f_spec.after = f_spec.afr_star;
	else
		f_spec.after = begin.afr_dot;
	return (f_spec);
}

t_all	ft_checkstar(t_formater begin, t_all f_spec)
{
	if (begin.has_star > 0)
		f_spec.width = f_spec.bfr_star;
	else
		f_spec.width = begin.width;
	return (f_spec);
}
