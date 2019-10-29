/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:16:27 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/29 22:09:32 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

fp_arg			*initialize_print_functions(void)
{
	fp_arg		*print;

	print = (fp_arg*)ft_memalloc(sizeof(fp_arg) * 17);
	print[C] = &print_c;
	print[I] = &print_int;
	print[F] = &print_float;
	print[S] = &print_s;
	print[P] = &print_p;
	print[PERCENT] = &print_percent;
	return (print);
}
