/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_parse.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/15 16:27:34 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 16:30:18 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_formater	ft_beginparse(void)
{
	t_formater begin;

	begin.has_dot = -1;
	begin.has_star = -1;
	begin.has_min = -1;
	begin.bfr_dot = -1;
	begin.afr_dot = -1;
	begin.width = -1;
	begin.star_bfr_dot = -1;
	begin.star_afr_dot = -1;
	begin.check = -1;
	begin.is_frmt_spec = -1;
	return (begin);
}

static t_counter	ft_begincount(const char *format_const)
{
	int				strlen;
	t_counter		count;

	strlen = 0;
	count.index = 0;
	count.nbr = 0;
	count.nbr_afr_dot = 0;
	count.nbr_bfr_dot = 0;
	count.check = 0;
	count.frmt_index = 1;
	count.frmt_cpy = ft_strdup(format_const);
	count.nbrstr = (char *)malloc(sizeof(char) * strlen);
	count.ns_afr_dot = (char *)malloc(sizeof(char) * strlen);
	count.ns_bfr_dot = (char *)malloc(sizeof(char) * strlen);
	strlen = ft_strlen_const(format_const);
	ft_bzero(count.nbrstr, strlen);
	ft_bzero(count.ns_afr_dot, strlen);
	ft_bzero(count.ns_bfr_dot, strlen);
	return (count);
}

static void			ft_finish_count(t_counter count)
{
	free(count.frmt_cpy);
	free(count.nbrstr);
	free(count.ns_afr_dot);
	free(count.ns_bfr_dot);
}

static t_formater	ft_finish_parse(t_formater begin, t_counter count)
{
	if (begin.index < 0)
		begin.index = count.index;
	else
		begin.index = count.index;
	begin.width = ft_atoi(count.nbrstr);
	begin.bfr_dot = ft_atoi(count.ns_bfr_dot);
	begin.afr_dot = ft_atoi(count.ns_afr_dot);
	return (begin);
}

t_formater			ft_parse(const char *format_const)
{
	t_formater		begin;
	t_counter		count;

	count = ft_begincount(format_const);
	begin = ft_beginparse();
	while (count.frmt_cpy[count.frmt_index] != '\0')
	{
		count.index++;
		begin = is_format_spec(begin, count.frmt_cpy[count.frmt_index]);
		if (begin.is_frmt_spec)
			break ;
		begin = ft_check_signs(begin, count);
		count = ft_check_number(begin, count);
		if (!count.check)
			break ;
		count.frmt_index++;
	}
	begin = ft_finish_parse(begin, count);
	ft_finish_count(count);
	return (begin);
}
