/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_00_04.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:54:22 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/15 16:36:03 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		get_char(va_list args)
{
	return((void)(va_arg(args, int)));
}

void		*get_signedchar(va_list args)
{
	return (&(va_arg(args, signed char)));
}

void		*get_unsignedchar(va_list args)
{
	return (&(va_args(args, unsigned char)));
}

void		*get_shortint(va_list args)
{
	return (&(va_args(args, short int)));
}

void		*get_unsignedshortint(va_list args)
{
	return (&(va_args(args, unsigned short int)));
}
