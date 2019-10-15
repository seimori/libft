/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:45:22 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/15 14:49:32 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_p(t_arg arg, t_specs *specs)
{
	int		arg_len;

	arg_len = 0;
	(void)specs;
	ft_putstr("0x");
	print_hexadecimal((unsigned long int)arg.p, specs);
	return (arg_len);
}
