/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:12:49 by imorimot          #+#    #+#             */
/*   Updated: 2019/04/29 19:11:34 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				fill_specs(const char *s, t_specs **specs)
{
	int			i;

	i = 1;
	i += fill_flags(s + i, specs);
	i += fill_fieldwidth(s + i, specs);
	i += fill_precision(s + i, specs);
	i += fill_lengthmodifier(s + i, specs);
	i += fill_conversion(s[i], specs);
	return (i);
}

void			print_char(t_arg arg)
{
	ft_putchar(arg.c);
}

void			print_int(t_arg arg)
{
	ft_putnbr(arg.i);
}

void			print_arg(va_list args, t_specs *specs)
{
	fp_arg		print[16];
	t_arg		arg;

	(void)specs;
	print[0] = &print_char;
	print[5] = &print_int;
	arg = (t_arg)va_arg(args, t_arg);
	print[specs->typeindex](arg);
	ft_putchar('\n');
}

void			ft_vprintf(const char *format, va_list args)
{
	t_specs		*specs;
	int			i;
	int			args_count;
	//void		*arg;
	//fp_arg		*get_arg;

	i = 0;
	args_count = 0;
	//get_arg = initialize_get_arg();
	while (format[i] != '\0')
	{
		i += print_til_percent(format + i);
		if (format[i] == '%')
		{
			args_count++;
			specs = initialize_specs();
			i += fill_specs(format + i, &specs);
			specs->typeindex = get_typeindex(specs);
			print_arg(args, specs);
		}
		else if (format[i] != '\0')
			i++;
	}
}
