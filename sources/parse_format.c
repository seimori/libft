/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:12:49 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/14 21:03:08 by imorimot         ###   ########.fr       */
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

int				print_args(const char *format, va_list args)
{
	t_specs		*specs;
	int			i;
	int			args_count;

	i = 0;
	args_count = 0;
	while (format[i] != '\0')
	{
		i += print_til_percent(format + i);
		if (format[i] == '%')
		{
			args_count++;
			specs = initialize_specs();
			i += fill_specs(format + i, &specs);
			get_arg_type(specs);
		}
		else
			i++;
	}
	return (specs);
}

int				main(void)
{
	t_specs	*specs;

	specs = print_args("hello%#042.-5Hfsalut");
	ft_putchar('\n');
	if (specs->flags)
	{
		ft_putstr("flags: ");
		ft_putstr(specs->flags);
		ft_putchar('\n');
	}
	if (specs->fieldwidth)
	{
		ft_putstr("fieldwidth: ");
		ft_putstr(specs->fieldwidth);
		ft_putchar('\n');
	}
	if (specs->precision)
	{
		ft_putstr("precision: ");
		ft_putstr(specs->precision);
		ft_putchar('\n');
	}
	if (specs->lengthmodifier)
	{
		ft_putstr("lengthmodifier: ");
		ft_putstr(specs->lengthmodifier);
		ft_putchar('\n');
	}
	if (specs->conversion)
	{
		ft_putstr("conversion: ");
		ft_putstr(specs->conversion);
		ft_putchar('\n');
	}

	return (0);
}
