/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:12:49 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/24 17:16:59 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				print_arg(va_list args, t_specs *specs, fp_arg *print)
{
	t_arg		arg;
	int			arg_len;

	if (specs->conversion == 'f')
		if (specs->lengthmodifier & BIG_L)
			arg = (t_arg)va_arg(args, long double);
		else
			arg = (t_arg)va_arg(args, double);
	else
		arg = (t_arg)va_arg(args, t_arg);
	arg_len = print[specs->typeindex](arg, specs);
	if (specs->flags & MINUS)
		arg_len = print_width(arg_len, specs);
	return (arg_len);
}
