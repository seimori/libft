/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:12:49 by imorimot          #+#    #+#             */
/*   Updated: 2019/05/02 17:34:19 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void			print_char(t_arg arg)
{
	ft_putchar(arg.c);
}

void			print_int(t_arg arg)
{
	ft_putnbr(arg.i);
}

static fp_arg	*initialize_print(void)
{
	fp_arg		*print;

	print = (fp_arg*)ft_memalloc(sizeof(fp_arg) * 16);
	print[0] = &print_char;
	print[5] = &print_int;
	return (print);
}

void			print_arg(va_list args, t_specs *specs)
{
	t_arg		arg;
	fp_arg		*print;

	(void)specs;
	arg = (t_arg)va_arg(args, t_arg);
	print = initialize_print();
	print[specs->typeindex](arg);
	ft_putchar('\n');
}
