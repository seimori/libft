/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:49:03 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/16 14:18:19 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		print_signed_decimal(long long int n, t_specs *specs)
{
	static int	count = 1;
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
		count++;
	}
	else
		ui_n = n;
	if (ui_n >= 10)
	{
		count++;
		print_signed_decimal(ui_n / 10, specs);
	}
	else if (!(specs->flags & MINUS))
		count = print_width(count, specs->width);
	ft_putchar(ui_n % 10 + '0');
	return (count);
}

int		print_unsigned_decimal(unsigned long long ui_n, t_specs *specs)
{
	static int	count = 1;

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
	{
		count++;
		print_unsigned_decimal(ui_n / 10, specs);
	}
	else if (!(specs->flags & MINUS))
		count = print_width(count, specs->width);
	ft_putchar(ui_n % 10 + '0');
	return (count);
}

int		print_octal(unsigned long long ui_n, t_specs *specs)
{
	static int	count = 1;

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
	{
		count++;
		print_octal(ui_n / 8, specs);
	}
	else if (!(specs->flags & MINUS))
		count = print_width(count, specs->width);
	ft_putchar(ui_n % 8 + '0');
	return (count);
}

int		print_hexadecimal(unsigned long long int ui_n, t_specs *specs)
{
	static int	count = 1;
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
	{
		count++;
		print_hexadecimal(ui_n / 16, specs);
	}
	else if (!(specs->flags & MINUS) && !(specs->conversion == 'p'))
		count = print_width(count, specs->width);
	ft_putchar(hexa[ui_n % 16]);
	return (count);
}

int		print_hexadecimal_big(unsigned long long int ui_n, t_specs *specs)
{
	static int	count = 1;
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
	{
		count++;
		print_hexadecimal_big(ui_n / 16, specs);
	}
	else if (!(specs->flags & MINUS))
		count = print_width(count, specs->width);
	ft_putchar(hexa[ui_n % 16]);
	return (count);
}
