/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_typeindex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:26:39 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/09 18:29:32 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
**	The order of typeindex is the same as the Wikipedia article
**	on C data types (https://en.wikipedia.org/wiki/C_data_types)
**	the order goes:
**	0: char
**	1: signed char
**	2: unsigned char
**	3: short int
**	4: unsigned short int
**	5: int
**	6: unsigned int
**	7: long int
**	8: unsigned long int
**	9: long long int
**	10: unsigned long long int
**	11: float
**	12: double
**	13: long double
**	14: char*
**	15: void*
*/

static int	get_int_typeindex(t_specs *specs)
{
	if (!specs->lengthmodifier)
		return (I);
	if (specs->lengthmodifier & HH)
		return (HHI);
	if (specs->lengthmodifier & H)
		return (HI);
	if (specs->lengthmodifier & L)
		return (LI);
	if (specs->lengthmodifier & LL)
		return (LLI);
	return (ERROR);
}

static int	get_unsignedint_typeindex(t_specs *specs)
{
	if (!specs->lengthmodifier)
		return (U);
	if (specs->lengthmodifier & HH)
		return (HHU);
	if (specs->lengthmodifier & H)
		return (HU);
	if (specs->lengthmodifier & L)
		return (LU);
	if (specs->lengthmodifier & LL)
		return (LLU);
	return (ERROR);
}

static int	get_float_typeindex(t_specs *specs)
{
	if (!specs->lengthmodifier)
		return (F);
	if (specs->lengthmodifier & L)
		return (LF);
	if (specs->lengthmodifier & LL)
		return (BIG_L_F);
	return (ERROR);
}

int			get_typeindex(t_specs *specs)
{
	if (specs->conversion == 'c')
		return (C);
	if (specs->conversion == 's')
		return (S);
	if (specs->conversion == 'p')
		return (P);
	if (specs->conversion == '%')
		return (PERCENT);
	if (specs->conversion == 'd' || specs->conversion == 'i'
			|| specs->conversion == 'o' || specs->conversion == 'x'
			|| specs->conversion == 'X')
		return (get_int_typeindex(specs));
	if (specs->conversion == 'u')
		return (get_unsignedint_typeindex(specs));
	if (specs->conversion == 'f')
		return (get_float_typeindex(specs));
	return (ERROR);
}
