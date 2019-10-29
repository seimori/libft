/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 19:35:38 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/30 00:06:39 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				print_width_string(t_specs *specs)
{
	while (specs->spaces_len + specs->arg_len < specs->width)
	{
		ft_putchar(' ');
		specs->spaces_len++;
	}
	return (specs->spaces_len);
}
