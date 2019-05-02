/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:48:38 by imorimot          #+#    #+#             */
/*   Updated: 2019/05/02 17:34:29 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int		print_til_percent(const char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\0'
			&& s[i] != '%')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

static t_specs	*initialize_specs(void)
{
	t_specs	*specs;

	specs = (t_specs*)ft_memalloc(sizeof(t_specs));
	specs->flags = NULL;
	specs->fieldwidth = NULL;
	specs->precision = NULL;
	specs->lengthmodifier = NULL;
	specs->conversion = NULL;
	specs->typeindex = -1;
	return (specs);
}

static int		fill_specs(const char *s, t_specs **specs)
{
	int			i;

	i = 1;
	i += fill_flags(s + i, specs);
	i += fill_fieldwidth(s + i, specs);
	i += fill_precision(s + i, specs);
	i += fill_lengthmodifier(s + i, specs);
	i += fill_conversion(s[i], specs);
	(*specs)->typeindex = get_typeindex(*specs);
	return (i);
}

void			ft_vprintf(const char *format, va_list args)
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
			print_arg(args, specs);
		}
		else if (format[i] != '\0')
			i++;
	}
}
