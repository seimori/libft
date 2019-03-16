/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:57:41 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/16 19:16:40 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_specs		*initialize_specs(void)
{
	t_specs	*specs;

	if (!(specs = (t_specs*)malloc(sizeof(t_specs))))
		return (NULL);
	specs->flags = NULL;
	specs->fieldwidth = NULL;
	specs->precision = NULL;
	specs->lengthmodifier = NULL;
	specs->conversion = NULL;
	specs->typeindex = -1;
	return (specs);
}

fp_arg		*initialize_get_arg(void)
{
	fp_arg	*get_arg;

	get_arg = malloc(sizeof(fp_arg) * 7);
	get_arg[0] = &get_int;
	/*
	get_arg[1] = &get_longint;
	get_arg[2] = &get_longlongint;
	get_arg[3] = &get_double;
	get_arg[4] = &get_longdouble;
	get_arg[5] = &get_string;
	get_arg[6] = &get_pointer;
	*/
	return (get_arg);
}
