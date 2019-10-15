/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:12:49 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/15 15:42:39 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				print_arg(va_list args, t_specs *specs, fp_arg *print)
{
	t_arg		arg;
	int			arg_len;

	arg = (t_arg)va_arg(args, t_arg);
	if (!(specs->flags & MINUS))
		print_width(arg, specs);
	arg_len = print[specs->typeindex](arg, specs);
	if (specs->flags & MINUS)
		print_width(arg, specs);
	if (specs->width > arg_len)
		arg_len = specs->width;
	return (arg_len);
}
