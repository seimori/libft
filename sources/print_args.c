/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 14:12:49 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/16 19:17:01 by imorimot         ###   ########.fr       */
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

void			*print_args(const char *format, va_list args)
//t_specs			*print_args(const char *format, va_list args)
//t_specs				*print_args(const char *format)
{
	t_specs		*specs;
	int			i;
	int			args_count;
	void		*arg;
	fp_arg		*get_arg;

	i = 0;
	args_count = 0;
	get_arg = initialize_get_arg();
	while (format[i] != '\0')
	{
		i += print_til_percent(format + i);
		if (format[i] == '%')
		{
			args_count++;
			specs = initialize_specs();
			i += fill_specs(format + i, &specs);
			specs->typeindex = get_typeindex(specs);
			arg = get_arg[0](args);
		}
		else if (format[i] != '\0')
			i++;
	}
	return (arg);
	//return (specs);
}

int				main(void)
{
	void		*arg;

	arg = ft_printf("hello%d", 42);
	ft_putchar('\n');
	ft_putnbr(*(int*)arg);
	ft_putchar('\n');
}
/*
**	Test specs
*/
/*
int				main(void)
{
	t_specs	*specs;

	specs = print_args("hello%ssalut");
	//specs = print_args("%d");
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
	ft_putstr("typeindex: ");
	ft_putnbr(specs->typeindex);
	ft_putchar('\n');

	return (0);
}
*/
