/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:45:30 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/29 22:04:01 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"

# include <stdio.h>//

# define SUCCESS 1
# define FAILURE 0
# define ERROR -1

/*
**	flags
*/
# define MINUS 1 << 0
# define PLUS 1 << 1
# define SPACE 1 << 2
# define ZERO 1 << 3
# define HASH 1 << 4

/*
**	lengthmodifier
*/
# define HH 1 << 0
# define H 1 << 1
# define L 1 << 2
# define LL 1 << 3
# define BIG_L 1 << 4

/*
**	typeindex
*/
# define C 0
# define I 1
# define F 2
# define S 3
# define P 4
# define PERCENT 5

typedef struct					s_specs
{
	unsigned char				flags;
	int							width;
	int							precision;
	unsigned char				lengthmodifier;
	char						conversion;
	int							typeindex;
	int							is_negative;
	int							is_zero;
	int							arg_len;
	int							spaces_len;
	unsigned long long			dot_left;
}								t_specs;

typedef union					u_arg
{
	char						c;
	signed char					hhi;
	unsigned char				hhu;
	short int					hi;
	unsigned short int			hu;
	int							i;
	unsigned int				u;
	long int					li;
	unsigned long int			lu;
	long long int				lli;
	unsigned long long int		llu;
	float						f;
	double						lf;
	long double					Lf;
	char						*s;
	void						*p;
}								t_arg;

typedef int				(*fp_arg)(t_arg, t_specs*);

/*
**	printf.c
*/
int						ft_printf(const char *format, ...);
int						ft_vprintf(const char *format, va_list args);

/*
**	initializers.c
*/	
fp_arg					*initialize_print_functions(void);

/*
**	printers
*/
int						print_c(t_arg arg, t_specs *specs);
int						print_int(t_arg arg, t_specs *specs);
int						print_float(t_arg arg, t_specs *specs);
int						print_s(t_arg arg, t_specs *specs);
int						print_p(t_arg arg, t_specs *specs);
int						print_percent(t_arg arg, t_specs *specs);

/*
**	print_numbers.c
*/
int						print_signed_decimal(long long int n, t_specs *specs);
int						print_unsigned_decimal(unsigned long long ui_n, t_specs *specs);
int						print_hexadecimal(unsigned long long int ui_n, t_specs *specs);
int						print_hexadecimal_big(unsigned long long int ui_n, t_specs *specs);
int						print_octal(unsigned long long int ui_n, t_specs *specs);

/*
**	print_options.c
*/
int						print_options(t_specs *specs);
int						print_width(t_specs *specs);
int						print_options_fpn(long double f, t_specs *specs);

/*
**	print_width_string.c
*/
int						print_width_string(t_specs *specs);

/*
**	print_precision.c
*/
int						print_precision(t_specs *specs);

/*
**	print_args.c
*/
int						print_arg(va_list args, t_specs *specs, fp_arg *print);

/*
**	tools.c
*/
int						ft_pow(int n, int pow);
int						ft_antoi(const char *s, int length);
void					ft_putstrn(const char *s, int length);
int						print_null(t_specs *specs);
int						is_error(t_specs *specs);


/*
**	get_typeindex.c
*/
int						get_typeindex(t_specs *specs);

/*
**	fillers.c
*/
int						fill_flags(const char *s, t_specs *specs);
int						fill_width(const char *s, t_specs *specs, va_list args);
int						fill_precision(const char *s, t_specs *specs, va_list args);
int						fill_lengthmodifier(const char *s, t_specs *specs);
int						fill_conversion(char c, t_specs *specs);

/*
**	identifiers.c
*/
int						is_flag(char c);
int						is_conversion(char c);

/*
**	extra.c
*/
void					print_specs(t_specs *specs);

#endif
