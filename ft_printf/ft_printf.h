/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adimitri <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/15 16:28:39 by adimitri      #+#    #+#                 */
/*   Updated: 2020/03/06 16:32:14 by adimitri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_formater
{
	char			type;
	int				width;
	int				index;
	int				has_min;
	int				has_dot;
	int				has_star;
	int				has_zero;
	int				bfr_dot;
	int				afr_dot;
	int				star_bfr_dot;
	int				star_afr_dot;
	int				check;
	int				is_frmt_spec;
}					t_formater;

typedef struct		s_counter
{
	char			*frmt_cpy;
	char			*nbrstr;
	char			*ns_afr_dot;
	char			*ns_bfr_dot;
	int				index;
	int				frmt_index;
	int				nbr;
	int				nbr_afr_dot;
	int				nbr_bfr_dot;
	int				check;
}					t_counter;

typedef struct		s_print
{
	va_list			list;
	t_formater		begin;
}					t_print;

typedef	struct		s_all
{
	int				len;
	int				bfr_min_afr;
	char			*str_to_prt;
	char			chr_to_prt;
	int				int_to_prt;
	unsigned int	uint_to_prt;
	unsigned int	hex_to_prt;
	unsigned long	ptr_to_prt;
	int				bfr_star;
	int				afr_star;
	int				before;
	int				after;
	int				width;
	int				zeroes;
	int				spaces;
	int				total_len;
	int				str_is_null;
}					t_all;

int					ft_printf(const char *format, ...);
int					ft_putchar(char c);
void				ft_putstr(char *str);
int					ft_strlen(char *str);
int					ft_strlen_const(const char *str);
int					ft_isdigit(int c);
int					ft_nbrlen(int n);
int					ft_unbrlen(unsigned int n);
char				*ft_itoa(int n);
char				*ft_uitoa(unsigned int n);
long				ft_atoi(char *n);
void				ft_putnbr(long n);
void				ft_putnbr_unsign(unsigned int n);
char				*ft_strdup(const char *s1);
char				*ft_itoa_base(unsigned long num, unsigned long base,
char c);
char				*ft_substr(char *s, unsigned int start, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_int_to_prt(t_all f_spec, int *count);
void				ft_printintchr(t_formater begin, int *count);
int					ft_spacepad(t_all f_spec, int nbrlen);
int					ft_checknbrlen(t_formater begin, t_all f_spec);
t_formater			ft_parse(const char *format_const);
t_formater			is_format_spec(t_formater begin, char c);
t_formater			ft_check_signs(t_formater begin, t_counter count);
t_counter			ft_check_number(t_formater begin, t_counter count);
t_all				ft_checkstar(t_formater begin, t_all f_spec);
t_all				ft_ifmin_wdot(t_formater begin, t_all f_spec, int min,
int *count);
t_all				ft_has_min_str(t_formater begin, t_all f_spec, int min,
int *count);
t_all				ft_nomin_wdot(t_formater begin, t_all f_spec, int *count);
t_all				ft_min_wdot(t_formater begin, t_all f_spec, int nbrlen);
t_all				ft_nomin_int(t_formater begin, t_all f_spec, int *count);
t_all				ft_nomin_uint(t_formater begin, t_all f_spec, int *count);
t_all				ft_zero_int(t_formater begin, t_all f_spec, int *count);
t_all				ft_zero_uint(t_formater begin, t_all f_spec, int *count);
t_all				ft_space_uint(t_formater begin, t_all f_spec, int *count);
t_all				ft_putspaces(t_all f_spec, int *count);
t_all				ft_check_dot(t_formater begin, t_all f_spec);
t_all				ft_len(t_all f_spec, int *count);
t_all				ft_has_min_str(t_formater begin, t_all f_spec, int min,
int *count);
t_all				ft_nomin_ptr(t_formater begin, t_all f_spec, int *count);
t_all				ft_ifmin_ptr(t_formater begin, t_all f_spec, int min,
int *count);
void				ft_printstr(va_list list, t_formater begin, t_all f_spec,
int *count);
void				ft_printchar(va_list list, t_formater begin, t_all f_spec,
int *count);
void				ft_printint(va_list list, t_formater begin, t_all f_spec,
int *count);
void				ft_printuint(va_list list, t_formater begin, t_all f_spec,
int *count);
void				ft_printhex(va_list list, t_formater begin, t_all f_spec,
int *count);
void				ft_printptr(va_list list, t_formater begin, t_all f_spec,
int *count);

#endif
