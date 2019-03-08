/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:53:19 by imorimot          #+#    #+#             */
/*   Updated: 2018/11/20 15:44:51 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
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
		ft_putnbr(ui_n / 10);
		ft_putchar(ui_n % 10 + '0');
	}
	else
		ft_putchar(ui_n % 10 + '0');
}
