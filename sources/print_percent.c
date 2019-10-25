/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:22:42 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/25 20:11:01 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_percent(t_arg arg, t_specs *specs)
{
	int		arg_len;

	(void)arg;
	arg_len = 1;
	if (!(specs->flags & MINUS))
		arg_len = print_width(arg_len, specs);
	ft_putchar('%');
	return (arg_len);
}
