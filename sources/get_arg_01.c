/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:54:57 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/16 19:35:22 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		*get_int(va_list args)
{
	int				*arg;

	if (!(arg = (int*)malloc(sizeof(int))))
		malloc_error();
	*arg = va_arg(args, int);
	return (arg);
}

void		*get_longint(va_list args)
{
	long int		*arg;

	if (!(arg = (long int*)malloc(sizeof(long int))))
		malloc_error();
	*arg = va_arg(args, long int);
	return (arg);
}

void		*get_longlongint(va_list args)
{
	long long int	*arg;

	if (!(arg = (long long int*)malloc(sizeof(long long int))))
		malloc_error();
	*arg = va_arg(args, long long int);
	return (arg);
}

void		*get_double(va_list args)
{
	double			*arg;

	if (!(arg = (double*)malloc(sizeof(double))))
		malloc_error();
	*arg = va_arg(args, double);
	return (arg);
}

void		*get_longdouble(va_list args)
{
	long double		*arg;

	if (!(arg = (long double*)malloc(sizeof(long double))))
		malloc_error();
	*arg = va_arg(args, long double);
	return (arg);
}

void		*get_pointer(va_list args)
{
	void			*arg;

	arg = va_arg(args, void*);
	return (arg);
}
