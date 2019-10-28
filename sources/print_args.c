/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:12:49 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/28 17:01:30 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				print_arg(va_list args, t_specs *specs, fp_arg *print)
{
	t_arg		arg;
	int			count;

	if (specs->conversion == 'f')
		if (specs->lengthmodifier & BIG_L)
			arg = (t_arg)va_arg(args, long double);
		else
			arg = (t_arg)va_arg(args, double);
	else
		arg = (t_arg)va_arg(args, t_arg);
	count = print[specs->typeindex](arg, specs);
	if (specs->flags & MINUS && specs->conversion == 's')
		count = print_width_string(specs) + specs->arg_len;
	else if (specs->flags & MINUS)
		count = print_width(specs) + specs->arg_len;
	return (count);
}
