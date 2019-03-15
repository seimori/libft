/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_typeindex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:26:39 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/14 18:16:41 by imorimot         ###   ########.fr       */
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

int			get_int_typeindex(t_specs *specs)
{
	if (!specs->lengthmodifier)
		return (5);
	if (ft_strequ("hh", specs->lengthmodifier))
		return (1);
	if (ft_strequ("h", specs->lengthmodifier))
		return (3);
	if (ft_strequ("l", specs->lengthmodifier))
		return (7);
	if (ft_strequ("ll", specs->lengthmodifier))
		return (9);
	return (-1);
}

int			get_unsignedint_typeindex(t_specs *specs)
{
	if (!specs->lengthmodifier)
		return (6);
	if (ft_strequ("hh", specs->lengthmodifier))
		return (2);
	if (ft_strequ("h", specs->lengthmodifier))
		return (4);
	if (ft_strequ("l", specs->lengthmodifier))
		return (8);
	if (ft_strequ("ll", specs->lengthmodifier))
		return (10);
	return (-1);
}

int			get_float_typeindex(t_specs *specs)
{
	if (!specs->lengthmodifier)
		return (11);
	if (ft_strequ("l", specs->lengthmodifier))
		return (12);
	if (ft_strequ("ll", specs->lengthmodifier))
		return (13);
	return (-1);
}

int			get_typeindex(t_specs *specs)
{
	if (is_charconversion(specs))
		return (0);
	if (is_stringconversion(specs))
		return (14);
	if (is_pointerconversion(specs))
		return (15);
	if (is_intconversion(specs))
		return (get_int_typeindex(specs));
	if (is_unsignedintconversion(specs))
		return (get_unsignedint_typeindex(specs));
	if (is_floatconversion(specs))
		return (get_float_typeindex(specs));
	return (-1);
}
