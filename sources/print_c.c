/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:01:09 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/09 18:43:15 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				print_c(t_arg arg, t_specs *specs)
{
	int		arg_len;

	arg_len = 1;
	(void)specs;
	ft_putchar(arg.c);
	return (arg_len);
}
