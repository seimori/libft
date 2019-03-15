/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:48:38 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/15 16:24:35 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

//int			ft_vprintf(const char *format, va_list args)
void			*ft_vprintf(const char *format, va_list args)
{
	//int			args_count;
	void		*arg;

	(void)args;
	arg = print_args(format, args);
	//print_args(format);

	return (arg);
}
