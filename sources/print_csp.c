/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:45:22 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/16 14:24:09 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				print_c(t_arg arg, t_specs *specs)
{
	int		arg_len;

	arg_len = 1;
	if (!(specs->flags & MINUS))
		arg_len = print_width(arg_len, specs->width);
	ft_putchar(arg.c);
	return (arg_len);
}

int				print_s(t_arg arg, t_specs *specs)
{
	int		arg_len;

	arg_len = ft_strlen(arg.s);
	if (!(specs->flags & MINUS))
		arg_len = print_width(arg_len, specs->width);
	ft_putstr(arg.s);
	return (arg_len);
}

int			print_p(t_arg arg, t_specs *specs)
{
	int		arg_len;

	ft_putstr("0x");
	arg_len = print_hexadecimal((unsigned long)arg.p, specs) + 2;
	return (arg_len);
}
