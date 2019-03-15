/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_05_09.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:54:57 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/15 16:21:10 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		*get_int(va_list args)
{
	return (&(va_args(args, int)));
}

void		*get_unsignedint(va_list args)
{
	return (&(va_args(args, unsigned int)));
}

void		*get_longint(va_list args)
{
	return (&(va_args(args, long int)));
}

void		*get_unsignedlongint(va_list args)
{
	return (&(va_args(args, unsigned long int)));
}

void		*get_longlongint(va_list args)
{
	return (&(va_args(args, long long int)));
}
