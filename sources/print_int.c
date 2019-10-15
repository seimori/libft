/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:45:19 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/15 19:02:34 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_int(t_arg arg, t_specs *specs)
{
	int		arg_len;

	arg_len = 1;
	if (specs->conversion == 'd' || specs->conversion == 'i')
		arg_len = print_signed_decimal(arg.lli, specs);
	else if (specs->conversion == 'u')
		arg_len = print_unsigned_decimal(arg.llu, specs);
	else if (specs->conversion == 'o')
		arg_len = print_octal(arg.llu, specs);
	else if (specs->conversion == 'x')
		arg_len = print_hexadecimal(arg.llu, specs);
	else if (specs->conversion == 'X')
		arg_len = print_hexadecimal_big(arg.llu, specs);
	return (arg_len);
}
