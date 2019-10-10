/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:45:30 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/10 19:06:42 by imorimot         ###   ########.fr       */
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
# define HHI 1
# define HHU 2
# define HI 3
# define HU 4
# define I 5
# define U 6
# define LI 7
# define LU 8
# define LLI 9
# define LLU 10
# define F 11
# define LF 12
# define BIG_L_F 13
# define S 14
# define P 15
# define PERCENT 16


typedef struct					s_specs
{
	unsigned char				flags;
	int							width;
	int							precision;
	unsigned char				lengthmodifier;
	char						conversion;
	int							typeindex;
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
int						print_s(t_arg arg, t_specs *specs);
int						print_p(t_arg arg, t_specs *specs);
int						print_percent(t_arg arg, t_specs *specs);

/*
**	print_numbers.c
*/
void					print_signed_decimal(long long int n, t_specs *specs);
void					print_unsigned_decimal(unsigned long long int ui_n, t_specs *specs);
void					print_hexadecimal(unsigned long long int ui_n, t_specs *specs);
void					print_hexadecimal_big(unsigned long long int ui_n, t_specs *specs);
void					print_octal(unsigned long long int ui_n, t_specs *specs);

/*
**	print_width.c
*/
void					print_width(t_arg arg, t_specs *specs);

/*
**	print_args.c
*/
int						print_arg(va_list args, t_specs *specs, fp_arg *print);

/*
**	ft_len.c
*/
int						ft_decimal_len(long long int i);
int						get_arg_len(t_arg arg, t_specs *specs);

/*
**	tools.c
*/
char					*ft_str_append(char *s, char c);
int						ft_pow(int n, int pow);
int						ft_antoi(const char *s, int length);


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
