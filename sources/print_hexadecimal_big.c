/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal_big.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:49:03 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/04 17:10:26 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	print_hexadecimal_big_char(unsigned char ui_n, int width)
{
	static char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (ui_n >= 16)
	{
		print_hexadecimal_big_char(ui_n / 16, width - 1);
		ft_putchar(hexa[ui_n % 16]);
	}
	else
	{
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
		}
		ft_putchar(hexa[ui_n % 16]);
	}
}

void	print_hexadecimal_big_short(unsigned short int ui_n, int width)
{
	static char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (ui_n >= 16)
	{
		print_hexadecimal_big_short(ui_n / 16, width - 1);
		ft_putchar(hexa[ui_n % 16]);
	}
	else
	{
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
		}
		ft_putchar(hexa[ui_n % 16]);
	}
}

void	print_hexadecimal_big(unsigned int ui_n, int width)
{
	static char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (ui_n >= 16)
	{
		print_hexadecimal_big(ui_n / 16, width - 1);
		ft_putchar(hexa[ui_n % 16]);
	}
	else
	{
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
		}
		ft_putchar(hexa[ui_n % 16]);
	}
}

void	print_hexadecimal_big_long(unsigned long int ui_n, int width)
{
	static char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (ui_n >= 16)
	{
		print_hexadecimal_big_long(ui_n / 16, width - 1);
		ft_putchar(hexa[ui_n % 16]);
	}
	else
	{
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
		}
		ft_putchar(hexa[ui_n % 16]);
	}
}

void	print_hexadecimal_big_long_long(unsigned long long int ui_n, int width)
{
	static char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (ui_n >= 16)
	{
		print_hexadecimal_big_long_long(ui_n / 16, width - 1);
		ft_putchar(hexa[ui_n % 16]);
	}
	else
	{
		while (width > 1)
		{
			ft_putchar(' ');
			width--;
		}
		ft_putchar(hexa[ui_n % 16]);
	}
}
