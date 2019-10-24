/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:59:38 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/24 20:07:22 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_precision(t_specs *specs, int num_len)
{
	while (num_len < specs->precision)
	{
		num_len++;
		ft_putchar('0');
	}

	return (num_len);
}
