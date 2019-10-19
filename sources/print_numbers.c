/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:49:03 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/19 17:31:21 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		print_signed_decimal(long long int n, t_specs *specs)
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
		g_count++;
	}
	else
		ui_n = n;
	if (ui_n >= 10)
	{
		g_count++;
		print_signed_decimal(ui_n / 10, specs);
	}
	else if (!(specs->flags & MINUS))
		g_count = print_width(g_count, specs->width);
	ft_putchar(ui_n % 10 + '0');
	return (g_count);
}

int		print_unsigned_decimal(unsigned long long ui_n, t_specs *specs)
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
	{
		g_count++;
		print_unsigned_decimal(ui_n / 10, specs);
	}
	else if (!(specs->flags & MINUS))
		g_count = print_width(g_count, specs->width);
	ft_putchar(ui_n % 10 + '0');
	return (g_count);
}

int		print_octal(unsigned long long ui_n, t_specs *specs)
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
	{
		g_count++;
		print_octal(ui_n / 8, specs);
	}
	else if (!(specs->flags & MINUS))
		g_count = print_width(g_count, specs->width);
	ft_putchar(ui_n % 8 + '0');
	return (g_count);
}

int		print_hexadecimal(unsigned long long int ui_n, t_specs *specs)
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
	{
		g_count++;
		print_hexadecimal(ui_n / 16, specs);
	}
	else if (!(specs->flags & MINUS) && !(specs->conversion == 'p'))
		g_count = print_width(g_count, specs->width);
	ft_putchar(hexa[ui_n % 16]);
	return (g_count);
}

int		print_hexadecimal_big(unsigned long long int ui_n, t_specs *specs)
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
	{
		g_count++;
		print_hexadecimal_big(ui_n / 16, specs);
	}
	else if (!(specs->flags & MINUS))
		g_count = print_width(g_count, specs->width);
	ft_putchar(hexa[ui_n % 16]);
	return (g_count);
}
