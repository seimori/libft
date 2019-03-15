/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:34:36 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/14 17:48:25 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			is_charconversion(t_specs *specs)
{
	return (ft_strequ("c", specs->conversion));
}

int			is_stringconversion(t_specs *specs)
{
	return (ft_strequ("s", specs->conversion));
}

int			is_pointerconversion(t_specs *specs)
{
	return (ft_strequ("p", specs->conversion));
}

int			is_floatconversion(t_specs *specs)
{
	return (ft_strequ("f", specs->conversion));
}
