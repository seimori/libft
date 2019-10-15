/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:46:16 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/15 15:25:19 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			ft_decimal_len(long long int i)
{
	int					len;
	unsigned long long	u_i;

	len = 1;
	if (i < 0)
	{
		u_i = -i;
		len++;
	}
	else
		u_i = i;
	while (u_i / 10 > 0)
	{
		len++;
		u_i /= 10;
	}
	return (len);
}

int			ft_decimal_len_unsigned(long long unsigned u_i)
{
	int					len;

	len = 1;
	while (u_i / 10 > 0)
	{
		len++;
		u_i /= 10;
	}
	return (len);
}

int			ft_octal_len(long long unsigned u_i)
{
	int					len;

	len = 1;
	while (u_i / 8 > 0)
	{
		len++;
		u_i /= 8;
	}
	return (len);
}

int			ft_hexadecimal_len(long long unsigned u_i)
{
	int					len;

	len = 1;
	while (u_i / 16 > 0)
	{
		len++;
		u_i /= 16;
	}
	return (len);
}

int			get_arg_len(t_arg arg, t_specs *specs)
{
	int		arg_len;

	arg_len = 1;
	if (specs->conversion == 'd'  || specs->conversion == 'i')
		arg_len = ft_decimal_len(arg.lli);
	else if (specs->conversion == 'u')
		arg_len = ft_decimal_len_unsigned(arg.llu);
	else if (specs->conversion == 'o')
		arg_len = ft_octal_len(arg.llu);
	else if (specs->conversion == 'x' || specs->conversion == 'X' ||
			specs->conversion == 'p')
		arg_len = ft_hexadecimal_len(arg.llu);
	return (arg_len);
}
