/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:45:22 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/04 19:00:23 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		print_p(t_arg arg, t_specs *specs)
{
	(void)specs;
	ft_putstr("0x");
	print_hexadecimal_long((unsigned long int)arg.p, 0);
}
