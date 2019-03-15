/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:57:41 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/15 16:30:24 by imorimot         ###   ########.fr       */
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

	get_arg = malloc(sizeof(fp_arg) * 16);
	get_arg[0] = &get_char;
	get_arg[1] = &get_signedchar;
	get_arg[2] = &get_unsignedchar;
	get_arg[3] = &get_shortint;
	get_arg[4] = &get_unsignedshortint;
	get_arg[5] = &get_int;
	get_arg[6] = &get_unsignedint;
	get_arg[7] = &get_longint;
	get_arg[8] = &get_unsignedlongint;
	get_arg[9] = &get_longlongint;
	get_arg[10] = &get_unsignedlonglongint;
	get_arg[11] = &get_float;
	get_arg[12] = &get_double;
	get_arg[13] = &get_longdouble;
	get_arg[14] = &get_string;
	get_arg[15] = &get_pointer;
	return (get_arg);
}
