/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:48:33 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/15 16:22:26 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>

//int		ft_printf(const char *format, ...)
void		*ft_printf(const char *format, ...)
{
	va_list		args;
	//int			args_count;
	void		*arg;

	va_start(args, format);
	arg = ft_vprintf(format, args);
	//args_count = vprintf(format, args);
	va_end(args);
	return (arg);
	//return (args_count);
}
