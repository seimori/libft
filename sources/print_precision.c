/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:59:38 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/23 17:06:17 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void			print_precision(t_specs *specs)
{
	while (g_count - specs->is_negative < specs->precision)
	{
		g_count++;
		ft_putchar('0');
	}
}
