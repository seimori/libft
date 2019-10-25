/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:08:13 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/25 21:46:45 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

#define NO_SPECIAL_CASES 0
int				is_hex_or_octal(t_specs *specs)
{
	return (specs->conversion == 'x' || specs->conversion == 'X'
			|| specs->conversion == 'o' || specs->conversion == 'p');
}

static void		print_sign(t_specs *specs)
{
	if (!(specs->flags & ZERO) && !(specs->conversion == '%'))
	{
		if (specs->is_negative == 1)
			ft_putchar('-');
		else if (specs->flags & PLUS)
			ft_putchar('+');
		else if (specs->flags & SPACE)
			ft_putchar(' ');
	}
}

int				sign_and_hash_offset(t_specs *specs)
{
	int			offset;

	offset = 0;
	if (specs->conversion == '%')
		return (0);
	if ((specs->is_negative == 1 || specs->flags & PLUS
				|| specs->flags & SPACE)
			&& !(is_hex_or_octal(specs)))
		offset += 1;
	if (specs->flags & HASH && !(specs->is_zero))
	{
		if (specs->conversion == 'x' || specs->conversion == 'X'
				|| specs->conversion == 'p')
			offset += 2;
		else if (specs->conversion == 'o' && specs->precision < specs->num_len
				&& !(specs->is_zero))
			offset += 1;
	}
	return (offset);
}

void			print_hash(t_specs *specs)
{
	if (specs->flags & HASH && !(specs->is_zero))
	{
		if (specs->conversion == 'x' || specs->conversion == 'p')
			ft_putstr("0x");
		else if (specs->conversion == 'X')
			ft_putstr("0X");
		else if (specs->conversion == 'o'
				&& specs->precision <= specs->num_len
				&& !(specs->is_zero))
			ft_putstr("0");
	}
}

char			print_flag_zero(t_specs *specs)
{
	char		width_char;

	if (specs->flags & ZERO)
	{
		width_char = '0';
		if (specs->is_negative)
			ft_putchar('-');
		else if (specs->flags & HASH && (is_hex_or_octal(specs)))
			print_hash(specs);
		else if (specs->flags & PLUS && !(is_hex_or_octal(specs)))
			ft_putchar('+');
	}
	else
		width_char = ' ';
	return (width_char);
}

int				print_width(t_specs *specs, char width_char)
{
	while (specs->spaces_len + specs->precision < specs->width
			&& specs->spaces_len + specs->num_len < specs->width)
	{
		ft_putchar(width_char);
		specs->spaces_len++;
	}
	return (specs->spaces_len);
}

int				print_options(int count, t_specs *specs)
{
	char		width_char;

	specs->num_len = count;
	specs->spaces_len += sign_and_hash_offset(specs);
	width_char = print_flag_zero(specs);
	specs->spaces_len = print_width(specs, width_char);
	print_sign(specs);
	if (!(specs->flags & ZERO))
			print_hash(specs);
	specs->num_len = print_precision(specs);
	count = specs->spaces_len + specs->num_len;
	return (count);
}

int						dot_left_len(long long int n)
{
	unsigned long long	u_n;
	int					count;

	count = 1;
	if (n < 0)
		u_n = (unsigned long long)-n;
	else
		u_n = (unsigned long long)n;
	while (u_n >= 10)
	{
		count++;
		u_n /= 10;
	}
	return (count);
}

int						get_num_len(long double f, t_specs *specs)
{
	int	count;

	count = 0;
	if (f < 0 || (1.0 / f == -1.0 / 0.0)
			|| specs->flags & PLUS
			|| specs->flags & SPACE)
		count++;
	count += dot_left_len((long long int)f);
	if (specs->precision != 0)
		count++;
	if (specs->precision < 0)
		count += 6;
	else
		count += specs->precision;
	return (count);
}

int						count_special_cases(long double f)
{
	if (f >= 1.0/0)
		return (3);
	if (f <= -1.0/0)
		return (4);
	if (f != f)
		return (3);
	return (0);
}

int						print_fpn_width(long double f, t_specs *specs)
{
	char	width_char;
	int		count;

	width_char = ' ';
	count = 0;
	specs->num_len = count_special_cases(f);
	if (specs->flags & ZERO)
	{
		width_char = '0';
		if (f < 0 || (1.0 / f == -1.0 / 0.0))
			ft_putchar('-');
		else if (specs->flags & PLUS)
			ft_putchar('+');
		else if (specs->flags & SPACE)
			ft_putchar(' ');
	}
	if (specs->num_len == NO_SPECIAL_CASES)
		specs->num_len = get_num_len(f, specs);
	while (specs->num_len + count < specs->width)
	{
		ft_putchar(width_char);
		count++;
	}
	return (count);
}
