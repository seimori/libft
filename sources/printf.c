/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:48:33 by imorimot          #+#    #+#             */
/*   Updated: 2019/04/29 19:03:14 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>

void		ft_printf(const char *format, ...)
{
	va_list		args;

	va_start(args, format);
	ft_vprintf(format, args);
	va_end(args);
}
