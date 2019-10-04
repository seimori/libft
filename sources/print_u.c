/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:48:40 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/04 15:49:05 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void			print_llu(t_arg arg, t_specs *specs)
{
	print_unsigned_decimal(arg.llu, specs->width);
}

void			print_lu(t_arg arg, t_specs *specs)
{
	print_unsigned_decimal(arg.lu, specs->width);
}

void			print_u(t_arg arg, t_specs *specs)
{
	print_unsigned_decimal(arg.u, specs->width);
}

void			print_hu(t_arg arg, t_specs *specs)
{
	print_unsigned_decimal(arg.hu, specs->width);
}

void			print_hhu(t_arg arg, t_specs *specs)
{
	print_unsigned_decimal(arg.hhu, specs->width);
}
