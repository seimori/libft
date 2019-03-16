/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:45:30 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/16 19:25:12 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef struct			s_specs
{
	char				*flags;
	char				*fieldwidth;
	char				*precision;
	char				*lengthmodifier;
	char				*conversion;
	int					typeindex;
}						t_specs;

typedef void			*(*fp_arg)(va_list);

/*
**	printf.c
*/
//int						ft_printf(const char *format, ...);
void						*ft_printf(const char *format, ...);
void						*ft_vprintf(const char *format, va_list args);

/*
**	errors.c
*/
void					malloc_error(void);

/*
**	print_args.c
*/
void					*print_args(const char *format, va_list args);
//t_specs					*print_args(const char *format, va_list args);
//t_specs						*print_args(const char *format);

/*
**	initializers.c
*/
t_specs					*initialize_specs(void);
fp_arg					*initialize_get_arg(void);

/*
**	printers.c
*/
int						print_til_percent(const char *s);

/*
**	tools.c
*/
char					*ft_str_append(char *s, char c);

/*
**	get_typeindex.c
*/
int						get_typeindex(t_specs *specs);

/*
**	fillers.c
*/
int						fill_flags(const char *s, t_specs **specs);
int						fill_fieldwidth(const char *s, t_specs **specs);
int						fill_precision(const char *s, t_specs **specs);
int						fill_lengthmodifier(const char *s, t_specs **specs);
int						fill_conversion(char c, t_specs **specs);

/*
**	identifiers.c
*/
int						is_flag(char c);
int						is_fieldwidth(char c);
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

/*
**	get_arg_01.c
*/
void					*get_int(va_list args);
/*
void					*get_longint(va_list args);
void					*get_longlongint(va_list args);
void					*get_double(va_list args);
void					*get_longdouble(va_list args);
void					*get_string(va_list args);
void					*get_pointer(va_list args);
*/


#endif
