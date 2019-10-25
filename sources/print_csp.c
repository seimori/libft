/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:45:22 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/25 21:33:03 by imorimot         ###   ########.fr       */
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
	int		arg_len;

	arg_len = ft_strlen(arg.s);
	if (!(specs->flags & MINUS))
		arg_len = print_options(arg_len, specs);
	ft_putstr(arg.s);
	return (arg_len);
}

int			print_p(t_arg arg, t_specs *specs)
{
	int		arg_len;

	g_count = G_COUNT_INIT_INT;
	specs->flags |= HASH;
	arg_len = print_hexadecimal((unsigned long)arg.p, specs);
	return (arg_len);
}
