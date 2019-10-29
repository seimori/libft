/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:16:27 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/29 23:07:13 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_fp_arg			*initialize_print_functions(void)
{
	t_fp_arg		*print;

	print = (t_fp_arg*)ft_memalloc(sizeof(t_fp_arg) * 6);
	print[C] = &print_c;
	print[I] = &print_int;
	print[F] = &print_float;
	print[S] = &print_s;
	print[P] = &print_p;
	print[PERCENT] = &print_percent;
	return (print);
}
