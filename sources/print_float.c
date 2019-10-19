/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:53:42 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/19 19:43:27 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

#define FPN_G_COUNT_INIT 0
#define ROUND_UP 0.5

void		ft_putnbr_ull(unsigned long long n)
{
	if (n >= 10)
		ft_putnbr_ull(n/10);
	ft_putchar(n % 10 + '0');
}

void		ft_putnbr_ull_nofirstdigit(unsigned long long n)
{
	if (n >= 10)
		ft_putnbr_ull_nofirstdigit(n / 10);
	if (g_count > 0)
		ft_putchar(n % 10 + '0');
	g_count++;
}

void		print_fpn(long double f, int precision, t_specs *specs)
{
	if (!(specs->lengthmodifier & BIG_L))
		f = (double)f;
	if (f < 0)
	{
		ft_putchar('-');
		f = -f;
	}
	ft_putnbr_ull((unsigned long long)f);
	ft_putchar('.');
	f -= (unsigned long long)f;
	f += 1;
	while (precision--)
		f *= 10;
	g_count = 0;
	ft_putnbr_ull_nofirstdigit((unsigned long long)(f + ROUND_UP));
}

int			print_float(t_arg arg, t_specs *specs)
{
	(void)specs;
	if (specs->lengthmodifier & BIG_L)
		print_fpn(arg.Lf, 6, specs);
	else
		print_fpn((long double)arg.lf, 6, specs);
	return (0);
}
