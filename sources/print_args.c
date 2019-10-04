/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:12:49 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/04 18:46:18 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static fp_arg	*initialize_print(void)
{
	fp_arg		*print;

	print = (fp_arg*)ft_memalloc(sizeof(fp_arg) * 16);
	print[C] = &print_c;
	print[HHI] = &print_hhi;
	print[HHU] = &print_hhu;
	print[HI] = &print_hi;
	print[HU] = &print_hu;
	print[I] = &print_i;
	print[LI] = &print_li;
	print[LU] = &print_lu;
	print[LLI] = &print_lli;
	print[LLU] = &print_llu;
	print[S] = &print_s;
	print[P] = &print_p;
	return (print);
}

void			print_arg(va_list args, t_specs *specs)
{
	t_arg		arg;
	fp_arg		*print;

	arg = (t_arg)va_arg(args, t_arg);
	print = initialize_print();
	print[specs->typeindex](arg, specs);
	free(print);
}
