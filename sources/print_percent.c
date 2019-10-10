/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:22:42 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/09 18:44:00 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			print_percent(t_arg arg, t_specs *specs)
{
	int		arg_len;

	arg_len = 1;
	(void)specs;
	(void)arg;
	ft_putchar('%');
	return (arg_len);
}
