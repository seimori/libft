/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:49:03 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/07 18:44:17 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	print_signed_decimal(long long int n, int type)
{
	unsigned int	ui_n;

	if (n < 0)
	{
		ui_n = -n;
		ft_putchar('-');
	}
	else
		ui_n = n;
	if (type == HHI)
		ui_n = (unsigned char)ui_n;
	if (type == HI)
		ui_n = (unsigned short)ui_n;
	if (type == I)
		ui_n = (unsigned int)ui_n;
	if (type == LI)
		ui_n = (unsigned long)ui_n;
	if (ui_n >= 10)
		print_signed_decimal(ui_n / 10, type);
	ft_putchar(ui_n % 10 + '0');
}

void	print_unsigned_decimal(unsigned long long int ui_n, int type)
{
	if (type == HHU)
		ui_n = (unsigned char)ui_n;
	if (type == HU)
		ui_n = (unsigned short)ui_n;
	if (type == U)
		ui_n = (unsigned int)ui_n;
	if (type == LU)
		ui_n = (unsigned long)ui_n;
	if (ui_n >= 10)
		print_unsigned_decimal(ui_n / 10, type);
	ft_putchar(ui_n % 10 + '0');
}

void	print_octal(unsigned long long ui_n, int type)
{
	if (type == HHI)
		ui_n = (unsigned char)ui_n;
	if (type == HI)
		ui_n = (unsigned short)ui_n;
	if (type == I)
		ui_n = (unsigned int)ui_n;
	if (type == LI)
		ui_n = (unsigned long)ui_n;
	if (ui_n >= 8)
		print_octal(ui_n / 8, type);
	ft_putchar(ui_n % 8 + '0');
}

void	print_hexadecimal(unsigned long long int ui_n, int type)
{
	static char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'a', 'b', 'c', 'd', 'e', 'f'};

	if (type == HHI)
		ui_n = (unsigned char)ui_n;
	if (type == HI)
		ui_n = (unsigned short)ui_n;
	if (type == I)
		ui_n = (unsigned int)ui_n;
	if (type == LI)
		ui_n = (unsigned long)ui_n;
	if (ui_n >= 16)
		print_hexadecimal(ui_n / 16, type);
	ft_putchar(hexa[ui_n % 16]);
}

void	print_hexadecimal_big(unsigned long long int ui_n, int type)
{
	static char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (type == HHI)
		ui_n = (unsigned char)ui_n;
	if (type == HI)
		ui_n = (unsigned short)ui_n;
	if (type == I)
		ui_n = (unsigned int)ui_n;
	if (type == LI)
		ui_n = (unsigned long)ui_n;
	if (ui_n >= 16)
		print_hexadecimal_big(ui_n / 16, type);
	ft_putchar(hexa[ui_n % 16]);
}
