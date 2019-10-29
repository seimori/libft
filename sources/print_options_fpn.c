/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options_fpn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:02:44 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 00:06:19 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

#define NO_SPECIAL_CASES 0

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

int						get_arg_len(long double f, t_specs *specs)
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
	if (f >= 1.0 / 0)
		return (3);
	if (f <= -1.0 / 0)
		return (4);
	if (f != f)
		return (3);
	return (0);
}

int						print_options_fpn(long double f, t_specs *specs)
{
	char	width_char;
	int		count;

	width_char = ' ';
	count = 0;
	specs->arg_len = count_special_cases(f);
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
	if (specs->arg_len == NO_SPECIAL_CASES)
		specs->arg_len = get_arg_len(f, specs);
	while (specs->arg_len + count < specs->width)
	{
		ft_putchar(width_char);
		count++;
	}
	return (count);
}
