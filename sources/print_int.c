/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:45:19 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/29 18:23:00 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

#define ARG_LEN_INIT_INT 1

t_specs		*remove_undefined_flags(t_specs *specs)
{
	if (specs->flags & ZERO && specs->flags & MINUS)
		specs->flags ^= ZERO;
	if ((!(specs->conversion == 'd') && !(specs->conversion == 'i'))
			&& specs->flags & PLUS)
		specs->flags ^= PLUS;
	if ((!(specs->conversion == 'd') && !(specs->conversion == 'i'))
			&& specs->flags & SPACE)
		specs->flags ^= SPACE;
	return (specs);
}

int			print_int(t_arg arg, t_specs *specs)
{
	specs = remove_undefined_flags(specs);
	specs->arg_len = ARG_LEN_INIT_INT;
	if (arg.i == 0)
	{
		specs->is_zero = 1;
		if (specs->precision == 0
				&& (!(specs->flags & HASH && specs->conversion == 'o')))
		{
			specs->arg_len = 0;
			return (print_width(specs));
		}
	}
	if (specs->conversion == 'd' || specs->conversion == 'i')
		specs->arg_len = print_signed_decimal(arg.lli, specs);
	else if (specs->conversion == 'u')
		specs->arg_len = print_unsigned_decimal(arg.llu, specs);
	else if (specs->conversion == 'o')
		specs->arg_len = print_octal(arg.llu, specs);
	else if (specs->conversion == 'x')
		specs->arg_len = print_hexadecimal(arg.llu, specs);
	else if (specs->conversion == 'X')
		specs->arg_len = print_hexadecimal_big(arg.llu, specs);
	return (specs->arg_len);
}
