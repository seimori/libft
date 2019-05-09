/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:45:30 by imorimot          #+#    #+#             */
/*   Updated: 2019/05/09 13:10:12 by imorimot         ###   ########.fr       */
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

# define CHAR 0
# define INT 5

typedef struct					s_specs
{
	char						*flags;
	int							width;
	int							precision;
	char						*lengthmodifier;
	char						*conversion;
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

typedef void					(*fp_arg)(t_arg, t_specs*);

/*
**	printf.c
*/
void					ft_printf(const char *format, ...);
void					ft_vprintf(const char *format, va_list args);

/*
**	put_int.c
*/
void					put_int_decimal(int n, int width);

/*
**	print_args.c
*/
void					print_arg(va_list args, t_specs *specs);

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
**	identifiers_conversion.c
*/
int						is_charconversion(t_specs *specs);
int						is_stringconversion(t_specs *specs);
int						is_pointerconversion(t_specs *specs);
int						is_floatconversion(t_specs *specs);

/*
**	identifiers_intconversion.c
*/
int						is_intconversion(t_specs *specs);
int						is_unsignedintconversion(t_specs *specs);

#endif
