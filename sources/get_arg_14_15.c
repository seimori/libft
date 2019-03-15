/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_14_15.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:56:12 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/15 15:56:56 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		*get_string(va_list args)
{
	return (&(va_args(args, char*)));
}

void		*get_pointer(va_list args)
{
	return (&(va_args(args, void*)));
}
