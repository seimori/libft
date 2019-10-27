/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:59:38 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/27 19:23:44 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_precision(t_specs *specs)
{
	while (specs->arg_len < specs->precision)
	{
		specs->arg_len++;
		ft_putchar('0');
	}

	return (specs->arg_len);
}
