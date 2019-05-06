/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:12:49 by imorimot          #+#    #+#             */
/*   Updated: 2019/05/06 15:35:40 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				ft_str_contains(char c, char *s)//
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

void			print_char(t_arg arg, t_specs *specs)
{
	(void)specs;
	ft_putchar(arg.c);
}

void			print_int(t_arg arg, t_specs *specs)
{
	(void)specs;
	ft_putnbr(arg.i);
}

static fp_arg	*initialize_print(void)
{
	fp_arg		*print;

	print = (fp_arg*)ft_memalloc(sizeof(fp_arg) * 16);
	print[CHAR] = &print_char;
	print[INT] = &print_int;
	return (print);
}

void			print_arg(va_list args, t_specs *specs)
{
	t_arg		arg;
	fp_arg		*print;

	arg = (t_arg)va_arg(args, t_arg);
	print = initialize_print();
	print[specs->typeindex](arg, specs);
}
