/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:49:03 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/04 17:15:04 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	print_octal_char(unsigned char ui_n, int width)
{
	if (ui_n >= 8)
	{
		print_octal_char(ui_n / 8, width - 1);
		ft_putchar(ui_n % 8 + '0');
	}
	else
	{
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
		}
		ft_putchar(ui_n % 8 + '0');
	}
}

void	print_octal_short(unsigned short ui_n, int width)
{
	if (ui_n >= 8)
	{
		print_octal_short(ui_n / 8, width - 1);
		ft_putchar(ui_n % 8 + '0');
	}
	else
	{
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
		}
		ft_putchar(ui_n % 8 + '0');
	}
}

void	print_octal(unsigned int ui_n, int width)
{
	if (ui_n >= 8)
	{
		print_octal(ui_n / 8, width - 1);
		ft_putchar(ui_n % 8 + '0');
	}
	else
	{
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
		}
		ft_putchar(ui_n % 8 + '0');
	}
}

void	print_octal_long(unsigned long ui_n, int width)
{
	if (ui_n >= 8)
	{
		print_octal_long(ui_n / 8, width - 1);
		ft_putchar(ui_n % 8 + '0');
	}
	else
	{
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
		}
		ft_putchar(ui_n % 8 + '0');
	}
}

void	print_octal_long_long(unsigned long long ui_n, int width)
{
	if (ui_n >= 8)
	{
		print_octal_long_long(ui_n / 8, width - 1);
		ft_putchar(ui_n % 8 + '0');
	}
	else
	{
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
		}
		ft_putchar(ui_n % 8 + '0');
	}
}
