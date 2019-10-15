/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:49:03 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/15 15:23:53 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	print_signed_decimal(long long int n, t_specs *specs)
{
	unsigned long long int	ui_n;

	if (specs->lengthmodifier & HH)
		n = (char)n;
	else if (specs->lengthmodifier & H)
		n = (short)n;
	else if (specs->lengthmodifier & L)
		n = (long)n;
	else if (specs->lengthmodifier & LL)
		n = (long long)n;
	else
		n = (int)n;
	if (n < 0)
	{
		ui_n = -n;
		ft_putchar('-');
	}
	else
		ui_n = n;
	if (ui_n >= 10)
		print_signed_decimal(ui_n / 10, specs);
	ft_putchar(ui_n % 10 + '0');
}

void	print_unsigned_decimal(unsigned long long int ui_n, t_specs *specs)
{
	if (specs->lengthmodifier & HH)
		ui_n = (unsigned char)ui_n;
	else if (specs->lengthmodifier & H)
		ui_n = (unsigned short)ui_n;
	else if (specs->lengthmodifier & L)
		ui_n = (unsigned long)ui_n;
	else if (specs->lengthmodifier & LL)
		ui_n = (unsigned long long)ui_n;
	else
		ui_n = (unsigned int)ui_n;
	if (ui_n >= 10)
		print_unsigned_decimal(ui_n / 10, specs);
	ft_putchar(ui_n % 10 + '0');
}

void	print_octal(unsigned long long ui_n, t_specs *specs)
{
	if (specs->lengthmodifier & HH)
		ui_n = (unsigned char)ui_n;
	else if (specs->lengthmodifier & H)
		ui_n = (unsigned short)ui_n;
	else if (specs->lengthmodifier & L)
		ui_n = (unsigned long)ui_n;
	else if (specs->lengthmodifier & LL)
		ui_n = (unsigned long long)ui_n;
	else
		ui_n = (unsigned int)ui_n;
	if (ui_n >= 8)
		print_octal(ui_n / 8, specs);
	ft_putchar(ui_n % 8 + '0');
}

void	print_hexadecimal(unsigned long long int ui_n, t_specs *specs)
{
	static char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'a', 'b', 'c', 'd', 'e', 'f'};

	if (specs->lengthmodifier & HH)
		ui_n = (unsigned char)ui_n;
	else if (specs->lengthmodifier & H)
		ui_n = (unsigned short)ui_n;
	else if (specs->lengthmodifier & L)
		ui_n = (unsigned long)ui_n;
	else if (specs->lengthmodifier & LL || specs->conversion == 'p')
		ui_n = (unsigned long long)ui_n;
	else
		ui_n = (unsigned int)ui_n;
	if (ui_n >= 16)
		print_hexadecimal(ui_n / 16, specs);
	ft_putchar(hexa[ui_n % 16]);
}

void	print_hexadecimal_big(unsigned long long int ui_n, t_specs *specs)
{
	static char hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9', 'A', 'B', 'C', 'D', 'E', 'F'};

	if (specs->lengthmodifier & HH)
		ui_n = (unsigned char)ui_n;
	else if (specs->lengthmodifier & H)
		ui_n = (unsigned short)ui_n;
	else if (specs->lengthmodifier & L)
		ui_n = (unsigned long)ui_n;
	else if (specs->lengthmodifier & LL)
		ui_n = (unsigned long long)ui_n;
	else
		ui_n = (unsigned int)ui_n;
	if (ui_n >= 16)
		print_hexadecimal_big(ui_n / 16, specs);
	ft_putchar(hexa[ui_n % 16]);
}
