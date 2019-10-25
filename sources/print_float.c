/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:53:42 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/25 19:14:17 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

#define FPN_G_COUNT_INIT 0
#define ROUND_UP 0.5

unsigned int	fpn_special_cases(long double f)
{
	if (f >= 1.0/0)
	{
		ft_putstr("inf");
		return (3);
	}
	if (f <= -1.0/0)
	{
		ft_putstr("-inf");
		return (4);
	}
	if (f != f)
	{
		ft_putstr("nan");
		return (3);
	}
	return (0);
}

unsigned int	ft_putnbr_ull(unsigned long long n)
{
	if (n >= 10)
		ft_putnbr_ull(n/10);
	ft_putchar(n % 10 + '0');
	g_count++;
	return (g_count);
}

unsigned int	ft_putnbr_ull_nofirstdigit(unsigned long long n)
{
	if (n >= 10)
		ft_putnbr_ull_nofirstdigit(n / 10);
	if (g_count > 0)
		ft_putchar(n % 10 + '0');
	g_count++;
	return (g_count - 1);
}

unsigned int	print_dot(int precision, t_specs *specs)
{
	(void)specs;
	if (precision > 0)
	{
		ft_putchar('.');
		return (1);
	}
	else
		return (0);
}

int				get_precision(int precision)
{
	if (precision < 0)
		return (6);
	else
		return (precision);
}

static int				print_sign(long double f, t_specs *specs)
{
	if (f < 0 || (1.0 / f == -1.0 / 0.0))
	{
		if (!(specs->flags & ZERO))
			ft_putchar('-');
		return (1);
	}
	else if (specs->flags & PLUS)
	{
		if (!(specs->flags & ZERO))
			ft_putchar('+');
		return (1);
	}
	else
		return (0);
}


unsigned int	print_fpn(long double f, t_specs *specs)
{
	unsigned int		count;
	int					precision;


	if ((count = fpn_special_cases(f)))
		return (count);
	precision = get_precision(specs->precision);
	if (!(specs->lengthmodifier & BIG_L))
		f = (double)f;
	g_count = print_sign(f, specs);
	if (f < 0 || (1.0 / f == -1.0 / 0.0))
		f = -f;
	count = ft_putnbr_ull((unsigned long long)f);
	count += print_dot(precision, specs);
	f -= (unsigned long long)f;
	f += 1;
	while (precision--)
		f *= 10;
	g_count = 0;
	count += ft_putnbr_ull_nofirstdigit((unsigned long long)(f + ROUND_UP));
	return (count);
}

int			print_float(t_arg arg, t_specs *specs)
{
	int			count;
	
	count = 0;
	if (specs->lengthmodifier & BIG_L)
	{
		if (!(specs->flags & MINUS))
			count = print_fpn_width(arg.Lf, specs);
		count += print_fpn(arg.Lf, specs);
	}
	else
	{
		if (!(specs->flags & MINUS))
			count = print_fpn_width((long double)arg.lf, specs);
		count += print_fpn((long double)arg.lf, specs);
	}
	return (count);
}
