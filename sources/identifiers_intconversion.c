/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers_intconversion.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:47:34 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/14 17:48:42 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			is_intconversion(t_specs *specs)
{
	return (ft_strequ("d", specs->conversion) ||
			ft_strequ("i", specs->conversion) ||
			ft_strequ("o", specs->conversion) ||
			ft_strequ("x", specs->conversion) ||
			ft_strequ("X", specs->conversion));
}

int			is_unsignedintconversion(t_specs *specs)
{
	return (ft_strequ("u", specs->conversion));
}
