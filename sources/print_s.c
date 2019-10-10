/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:05:50 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/09 14:51:22 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				print_s(t_arg arg, t_specs *specs)
{
	(void)specs;
	ft_putstr(arg.s);
	return (ft_strlen(arg.s));
}
