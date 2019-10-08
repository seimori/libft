/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:48:40 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/07 18:43:54 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void			print_llu(t_arg arg, t_specs *specs)
{
	(void)specs;
	print_unsigned_decimal(arg.llu, LLU);
}

void			print_lu(t_arg arg, t_specs *specs)
{
	(void)specs;
	print_unsigned_decimal(arg.lu, LU);
}

void			print_u(t_arg arg, t_specs *specs)
{
	(void)specs;
	print_unsigned_decimal(arg.u, U);
}

void			print_hu(t_arg arg, t_specs *specs)
{
	(void)specs;
	print_unsigned_decimal(arg.hu, HU);
}

void			print_hhu(t_arg arg, t_specs *specs)
{
	(void)specs;
	print_unsigned_decimal(arg.hhu, HHU);
}
