/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:16:27 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/19 17:02:07 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

fp_arg			*initialize_print_functions(void)
{
	fp_arg		*print;

	print = (fp_arg*)ft_memalloc(sizeof(fp_arg) * 16);
	print[C] = &print_c;
	print[HHI] = &print_int;
	print[HHU] = &print_int;
	print[HI] = &print_int;
	print[HU] = &print_int;
	print[I] = &print_int;
	print[U] = &print_int;
	print[LI] = &print_int;
	print[LU] = &print_int;
	print[LLI] = &print_int;
	print[LLU] = &print_int;
	print[F] = &print_float;
	print[LF] = &print_float;
	print[BIG_L_F] = &print_float;
	print[S] = &print_s;
	print[P] = &print_p;
	print[PERCENT] = &print_percent;
	return (print);
}
