/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:45:22 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/27 19:27:59 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

#define G_COUNT_INIT_INT 1

int				print_c(t_arg arg, t_specs *specs)
{
	int		arg_len;

	arg_len = 1;
	if (!(specs->flags & MINUS))
		arg_len = print_options(arg_len, specs);
	ft_putchar(arg.c);
	return (arg_len);
}

int				print_s(t_arg arg, t_specs *specs)
{
	specs->arg_len = ft_strlen(arg.s);
	if (specs->arg_len > specs->precision && specs->precision > -1)
		specs->arg_len = specs->precision;
	if (!(specs->flags & MINUS))
		specs->spaces_len = print_width(specs);
	if (specs->precision <= -1 || specs->arg_len < specs->precision)
		ft_putstr(arg.s);
	else
		ft_putstrn(arg.s, specs->precision);
	return (specs->arg_len + specs->spaces_len);
}

int			print_p(t_arg arg, t_specs *specs)
{
	int		arg_len;

	g_count = G_COUNT_INIT_INT;
	specs->flags |= HASH;
	arg_len = print_hexadecimal((unsigned long)arg.p, specs);
	return (arg_len);
}
