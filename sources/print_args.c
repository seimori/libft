/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:12:49 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/03 17:25:30 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static fp_arg	*initialize_print(void)
{
	fp_arg		*print;

	print = (fp_arg*)ft_memalloc(sizeof(fp_arg) * 16);
	print[C] = &print_char;
	print[HHI] = &print_int;
	print[HHU] = &print_unsigned_int;
	print[HI] = &print_int;
	print[HU] = &print_unsigned_int;
	print[I] = &print_int;
	print[S] = &print_string;
	return (print);
}

void			print_arg(va_list args, t_specs *specs)
{
	t_arg		arg;
	fp_arg		*print;

	arg = (t_arg)va_arg(args, t_arg);
	print = initialize_print();
	print[specs->typeindex](arg, specs);
}
