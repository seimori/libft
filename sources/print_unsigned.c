/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:27:57 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/04 16:49:22 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	print_unsigned_decimal(unsigned long long int ui_n, int width)
{
	if (ui_n >= 10)
	{
		print_unsigned_decimal(ui_n / 10, width - 1);
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
