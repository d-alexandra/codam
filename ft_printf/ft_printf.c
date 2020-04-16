/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/19 14:11:55 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 16:27:40 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_formater		is_format_spec(t_formater begin, char c)
{
	if (c == 'c')
		begin.is_frmt_spec = 1;
	else if (c == 's')
		begin.is_frmt_spec = 1;
	else if (c == 'd')
		begin.is_frmt_spec = 1;
	else if (c == 'i')
		begin.is_frmt_spec = 1;
	else if (c == 'u')
		begin.is_frmt_spec = 1;
	else if (c == 'p')
		begin.is_frmt_spec = 1;
	else if (c == 'x')
		begin.is_frmt_spec = 1;
	else if (c == 'X')
		begin.is_frmt_spec = 1;
	else if (c == '%')
		begin.is_frmt_spec = 1;
	else
		begin.is_frmt_spec = 0;
	begin.type = c;
	return (begin);
}

static t_print	ft_all(t_print p, t_all f_spec, int *count, int index)
{
	if (p.begin.type == 'c' && index > 1)
		ft_printchar(p.list, p.begin, f_spec, count);
	if (p.begin.type == '%')
		ft_printchar(p.list, p.begin, f_spec, count);
	else if (p.begin.type == '%' && index == 1)
		ft_putchar('%');
	if (p.begin.type == 's')
		ft_printstr(p.list, p.begin, f_spec, count);
	if (p.begin.type == 'd' || p.begin.type == 'i')
		ft_printint(p.list, p.begin, f_spec, count);
	if (p.begin.type == 'u')
		ft_printuint(p.list, p.begin, f_spec, count);
	if (p.begin.type == 'x' || p.begin.type == 'X')
		ft_printhex(p.list, p.begin, f_spec, count);
	if (p.begin.type == 'p')
		ft_printptr(p.list, p.begin, f_spec, count);
	return (p);
}

static void		ft_vfprintf(t_print p, const char *format, t_all f_spec,
int *count)
{
	int			index;

	index = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			p.begin = ft_parse(format);
			index = p.begin.index;
			p = ft_all(p, f_spec, count, index);
		}
		else
			*count = *count + ft_putchar(*format);
		if (*format == '%' && index == 0)
		{
			*count = *count + ft_putchar(*format);
			index--;
		}
		format++;
		while (index >= 1)
		{
			format++;
			index--;
		}
	}
}

int				ft_printf(const char *format, ...)
{
	t_print		p;
	t_all		f_spec;
	int			count;

	count = 0;
	f_spec.str_to_prt = (char *)malloc(sizeof(char) * ft_strlen_const(format));
	va_start(p.list, format);
	ft_vfprintf(p, format, f_spec, &count);
	va_end(p.list);
	free(f_spec.str_to_prt);
	return (count);
}

#include <stdio.h>

int main()
{
	int i = -50;
	int j = 30;

	while (i < 50)
	{
		ft_printf("|%-*.*s|\n", i, j, "hello");
		printf("|%-*.*s|\n", i, j, "hello");
		i++;
	}
	return (0);
}