/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_decimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:57:31 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/04 15:45:40 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	print_signed_decimal(long long int n, int width)
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
		print_signed_decimal(ui_n / 10, width - 1);
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
