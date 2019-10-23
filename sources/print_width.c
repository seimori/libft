/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:08:13 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/23 20:03:27 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_width(int count, t_specs *specs)
{
	char		width_char;

	if (specs->flags & PLUS)
		count++;
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
	while (count < specs->width)
	{
		ft_putchar(width_char);
		count++;
	}
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

int						get_longdouble_len(long double f, int precision)
{
	int	count;

	count = 0;
	if (f < 0 || (1.0 / f == -1.0 / 0.0))
		count++;
	count += llint_len((long long int)f);
	if (precision != 0)
		count++;
	if (precision < 0)
		count += 6;
	else
		count += precision;
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
		}
		count = 0;
		arg_len = get_longdouble_len(f, specs->precision);
	}
	while (arg_len + count < specs->width)
	{
		ft_putchar(width_char);
		count++;
	}
	return (count);
}
