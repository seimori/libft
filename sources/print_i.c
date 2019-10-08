/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:45:19 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/07 19:39:38 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void			print_lli(t_arg arg, t_specs *specs)
{
	if (specs->conversion == 'd' || specs->conversion == 'i')
		print_signed_decimal(arg.lli, LLI);
	else if (specs->conversion == 'o')
		print_octal(arg.lli, LLI);
	else if (specs->conversion == 'x')
		print_hexadecimal(arg.lli, LLI);
	else if (specs->conversion == 'X')
		print_hexadecimal_big(arg.lli, LLI);
}

void			print_li(t_arg arg, t_specs *specs)
{
	if (specs->conversion == 'd' || specs->conversion == 'i')
		print_signed_decimal(arg.li, LI);
	else if (specs->conversion == 'o')
		print_octal(arg.li, LI);
	else if (specs->conversion == 'x')
		print_hexadecimal(arg.li, LI);
	else if (specs->conversion == 'X')
		print_hexadecimal_big(arg.li, LI);
}

void			print_i(t_arg arg, t_specs *specs)
{
	if (specs->conversion == 'd' || specs->conversion == 'i')
		print_signed_decimal(arg.i, I);
	else if (specs->conversion == 'o')
		print_octal(arg.i, I);
	else if (specs->conversion == 'x')
		print_hexadecimal(arg.i, I);
	else if (specs->conversion == 'X')
		print_hexadecimal_big(arg.i, I);
}

void			print_hi(t_arg arg, t_specs *specs)
{
	if (specs->conversion == 'd' || specs->conversion == 'i')
		print_signed_decimal(arg.hi, HI);
	else if (specs->conversion == 'o')
		print_octal(arg.hi, HI);
	else if (specs->conversion == 'x')
		print_hexadecimal(arg.hi, HI);
	else if (specs->conversion == 'X')
		print_hexadecimal_big(arg.hi, HI);
}

void			print_hhi(t_arg arg, t_specs *specs)
{
	if (specs->conversion == 'd' || specs->conversion == 'i')
		print_signed_decimal(arg.hhi, HHI);
	else if (specs->conversion == 'o')
		print_octal(arg.hhi, HHI);
	else if (specs->conversion == 'x')
		print_hexadecimal(arg.hhi, HHI);
	else if (specs->conversion == 'X')
		print_hexadecimal_big(arg.hhi, HHI);
}
