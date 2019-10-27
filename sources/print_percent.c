/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:22:42 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/27 14:40:10 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_percent(t_arg arg, t_specs *specs)
{
	(void)arg;
	specs->num_len = 1;
	if (!(specs->flags & MINUS))
		specs->num_len = print_options(specs->num_len, specs);
	ft_putchar('%');
	return (specs->num_len);
}
