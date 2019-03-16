/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_05_09.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:54:57 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/16 19:00:51 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		*get_int(va_list args)
{
	int		i;

	i = va_args(args, int);
	return (&i);
}

void		*get_longint(va_list args)
{
	return (&(va_args(args, long int)));
}

void		*get_longlongint(va_list args)
{
	return (&(va_args(args, long long int)));
}

void		*get_double(va_list args)
{
	return (&(va_args(args, double)));
}

void		*get_longdouble(va_list args)
{
	return (&(va_args(args, long double)));
}

void		*get_string(va_list args)
{
	return (&(va_args(args, char*)));
}

void		*get_pointer(va_list args)
{
	return (&(va_args(args, void*)));
}
