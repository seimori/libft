/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:18:58 by imorimot          #+#    #+#             */
/*   Updated: 2019/05/07 18:41:50 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_putint_width(int n, int width)
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
		ft_putint_width(ui_n / 10, width - 1);
		ft_putchar(ui_n % 10 + '0');
	}
	else
	{
		while (width > 1)
		{
			ft_putchar('*');
			width--;
		}
		ft_putchar(ui_n % 10 + '0');
	}
}
