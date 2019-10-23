/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:08:13 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/23 16:48:07 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_width(int count, int width)
{
	while (count < width)
	{
		ft_putchar(' ');
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

int						print_fpn_width(long double f, t_specs *specs)
{
	int		longdouble_len;
	int		count;

	count = 0;
	longdouble_len = get_longdouble_len(f, specs->precision);
	while (longdouble_len + count < specs->width)
	{
		ft_putchar(' ');
		count++;
	}
	return (count);
}
