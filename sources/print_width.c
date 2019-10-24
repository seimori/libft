/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:08:13 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/24 19:46:50 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char			print_flag_zero(t_specs *specs)
{
	char		width_char;

	if (specs->flags & ZERO)
	{
		width_char = '0';
		if (specs->is_negative)
			ft_putchar('-');
		else if (specs->flags & PLUS)
			ft_putchar('+');
	}
	else
		width_char = ' ';
	return (width_char);
}

static void		print_sign(t_specs *specs)
{
	if (!(specs->flags & ZERO))
	{
		if (specs->is_negative == 1)
			ft_putchar('-');
		else if (specs->flags & PLUS)
			ft_putchar('+');
	}
}

int				print_width(int count, t_specs *specs)
{
	int			num_len;
	int			spaces_len;
	char		width_char;

	num_len = count;
	spaces_len = 0;
	if (specs->is_negative == 1 || specs->flags & PLUS)
		spaces_len++;
	width_char = print_flag_zero(specs);
	while (spaces_len + specs->precision < specs->width
			&& spaces_len + num_len < specs->width)
	{
		ft_putchar(width_char);
		spaces_len++;
	}
	print_sign(specs);
	num_len = print_precision(specs, num_len);
	count = spaces_len + num_len;
	return (count);
}

int						llint_len(long long int n)
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

int						get_longdouble_len(long double f, t_specs *specs)
{
	int	count;

	count = 0;
	if (f < 0 || (1.0 / f == -1.0 / 0.0))
		count++;
	else if (specs->flags & PLUS)
		count++;
	count += llint_len((long long int)f);
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
	int		arg_len;

	width_char = ' ';
	if ((arg_len = count_special_cases(f)))
		count = 0;
	else
	{
		if (specs->flags & ZERO)
		{
			width_char = '0';
			if (f < 0 || (1.0 / f == -1.0 / 0.0))
				ft_putchar('-');
			if (specs->flags & PLUS)
				ft_putchar('+');
		}
		count = 0;
		arg_len = get_longdouble_len(f, specs);
	}
	while (arg_len + count < specs->width)
	{
		ft_putchar(width_char);
		count++;
	}
	return (count);
}
