/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:45:19 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/15 15:04:32 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_int(t_arg arg, t_specs *specs)
{
	if (specs->conversion == 'd' || specs->conversion == 'i')
		print_signed_decimal(arg.lli, specs);
	else if (specs->conversion == 'u')
		print_unsigned_decimal(arg.llu, specs);
	else if (specs->conversion == 'o')
		print_octal(arg.llu, specs);
	else if (specs->conversion == 'x')
		print_hexadecimal(arg.llu, specs);
	else if (specs->conversion == 'X')
		print_hexadecimal_big(arg.llu, specs);
	return (get_arg_len(arg, specs));
}
