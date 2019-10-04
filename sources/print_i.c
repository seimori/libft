/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:45:19 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/04 17:19:17 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void			print_lli(t_arg arg, t_specs *specs)
{
	if (specs->conversion == 'd' || specs->conversion == 'i')
		print_signed_decimal(arg.lli, specs->width);
	else if (specs->conversion == 'o')
		print_octal_long_long(arg.lli, specs->width);
	else if (specs->conversion == 'x')
		print_hexadecimal_long_long(arg.lli, specs->width);
	else if (specs->conversion == 'X')
		print_hexadecimal_big_long_long(arg.lli, specs->width);
}

void			print_li(t_arg arg, t_specs *specs)
{
	if (specs->conversion == 'd' || specs->conversion == 'i')
		print_signed_decimal(arg.li, specs->width);
	else if (specs->conversion == 'o')
		print_octal_long(arg.li, specs->width);
	else if (specs->conversion == 'x')
		print_hexadecimal_long(arg.li, specs->width);
	else if (specs->conversion == 'X')
		print_hexadecimal_big_long(arg.li, specs->width);
}

void			print_i(t_arg arg, t_specs *specs)
{
	if (specs->conversion == 'd' || specs->conversion == 'i')
		print_signed_decimal(arg.i, specs->width);
	else if (specs->conversion == 'o')
		print_octal(arg.i, specs->width);
	else if (specs->conversion == 'x')
		print_hexadecimal(arg.i, specs->width);
	else if (specs->conversion == 'X')
		print_hexadecimal_big(arg.i, specs->width);
}

void			print_hi(t_arg arg, t_specs *specs)
{
	if (specs->conversion == 'd' || specs->conversion == 'i')
		print_signed_decimal(arg.hi, specs->width);
	else if (specs->conversion == 'o')
		print_octal_short(arg.hi, specs->width);
	else if (specs->conversion == 'x')
		print_hexadecimal_short(arg.hi, specs->width);
	else if (specs->conversion == 'X')
		print_hexadecimal_big_short(arg.hi, specs->width);
}

void			print_hhi(t_arg arg, t_specs *specs)
{
	if (specs->conversion == 'd' || specs->conversion == 'i')
		print_signed_decimal(arg.hhi, specs->width);
	else if (specs->conversion == 'o')
		print_octal_char(arg.hhi, specs->width);
	else if (specs->conversion == 'x')
		print_hexadecimal_char(arg.hhi, specs->width);
	else if (specs->conversion == 'X')
		print_hexadecimal_big_char(arg.hhi, specs->width);
}
