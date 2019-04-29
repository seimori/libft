/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:57:41 by imorimot          #+#    #+#             */
/*   Updated: 2019/04/29 19:04:10 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_specs		*initialize_specs(void)
{
	t_specs	*specs;

	specs = (t_specs*)ft_memalloc(sizeof(t_specs));
	specs->flags = NULL;
	specs->fieldwidth = NULL;
	specs->precision = NULL;
	specs->lengthmodifier = NULL;
	specs->conversion = NULL;
	specs->typeindex = -1;
	return (specs);
}
