/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:46:16 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/10 15:00:55 by imorimot         ###   ########.fr       */
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

int			get_arg_len(t_arg arg, t_specs *specs)
{
	int		arg_len;

	arg_len = 1;
	if (specs->conversion == 'd'  || specs->conversion == 'i')
		arg_len = ft_decimal_len(arg.i);
	return (arg_len);
}
