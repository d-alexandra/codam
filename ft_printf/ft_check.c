/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/15 17:16:16 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 16:30:57 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_formater	ft_check_star(t_formater begin)
{
	if (begin.has_dot > 0)
		begin.star_afr_dot = 1;
	else
		begin.star_bfr_dot = 1;
	begin.has_star = 1;
	return (begin);
}

static	t_formater	ft_check_zero(t_formater begin, t_counter count)
{
	if (count.nbr <= 0)
	{
		begin.has_zero = 1;
		begin.check = 1;
	}
	return (begin);
}

t_formater			ft_check_signs(t_formater begin, t_counter count)
{
	if (count.frmt_cpy[count.frmt_index] == '.')
	{
		begin.has_dot = 1;
		begin.check = 1;
	}
	else if (count.frmt_cpy[count.frmt_index] == '*')
	{
		begin = ft_check_star(begin);
		begin.check = 1;
	}
	else if (count.frmt_cpy[count.frmt_index] == '-')
	{
		begin.has_min = 1;
		begin.check = 1;
	}
	else if (count.frmt_cpy[count.frmt_index] == '0')
		begin = ft_check_zero(begin, count);
	else
		begin.check = 0;
	return (begin);
}

static t_counter	ft_is_number(t_formater begin, t_counter count)
{
	if (begin.has_dot > 0)
	{
		count.ns_afr_dot[count.nbr_afr_dot] = count.frmt_cpy[count.frmt_index];
		count.nbr_afr_dot++;
	}
	else
	{
		count.ns_bfr_dot[count.nbr_bfr_dot] = count.frmt_cpy[count.frmt_index];
		count.nbr_bfr_dot++;
	}
	count.nbrstr[count.nbr] = count.frmt_cpy[count.frmt_index];
	count.nbr++;
	return (count);
}

t_counter			ft_check_number(t_formater begin, t_counter count)
{
	if (begin.check)
		count.check = 1;
	else if (ft_isdigit(count.frmt_cpy[count.frmt_index]))
	{
		count = ft_is_number(begin, count);
		count.check = 1;
	}
	else
		count.check = 0;
	return (count);
}
