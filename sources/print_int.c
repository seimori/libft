/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:57:31 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/03 17:31:18 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	print_int_decimal(int n, int width)
{
	unsigned int	ui_n;

	if (n < 0)
	{
		ui_n = -n;
		ft_putchar('-');
	}
	else
		ui_n = n;
	if (ui_n >= 10)
	{
		print_int_decimal(ui_n / 10, width - 1);
		ft_putchar(ui_n % 10 + '0');
	}
	else
	{
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
		}
		ft_putchar(ui_n % 10 + '0');
	}
}

void			print_int(t_arg arg, t_specs *specs)
{
	print_int_decimal(arg.i, specs->width);
}
