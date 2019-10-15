/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:45:22 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/15 19:02:50 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				print_c(t_arg arg, t_specs *specs)
{
	int		arg_len;

	arg_len = 1;
	(void)specs;
	ft_putchar(arg.c);
	return (arg_len);
}

int				print_s(t_arg arg, t_specs *specs)
{
	(void)specs;
	ft_putstr(arg.s);
	return (ft_strlen(arg.s));
}

int			print_p(t_arg arg, t_specs *specs)
{
	ft_putstr("0x");
	return (print_hexadecimal((unsigned long int)arg.p, specs) + 2);
}
