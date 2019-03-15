/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_10_14.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:55:28 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/15 15:56:00 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		*get_unsignedlonglongint(va_list args)
{
	return (&(va_args(args, unsigned long long int)));
}

void		*get_float(va_list args)
{
	return (&(va_args(args, float)));
}

void		*get_double(va_list args)
{
	return (&(va_args(args, double)));
}

void		*get_longdouble(va_list args)
{
	return (&(va_args(args, long double)));
}
