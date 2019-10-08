/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:48:38 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/08 19:10:03 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int		fill_specs(const char *s, t_specs *specs, va_list args)
{
	int			i;

	i = 1;
	i += fill_flags(s + i, specs);
	i += fill_width(s + i, specs, args);
	i += fill_precision(s + i, specs, args);
	i += fill_lengthmodifier(s + i, specs);
	i += fill_conversion(s[i], specs);
	specs->typeindex = get_typeindex(specs);
	return (i);
}

static t_specs	*initialize_specs(void)
{
	t_specs	*specs;

	specs = (t_specs*)ft_memalloc(sizeof(t_specs));
	specs->flags = 0;
	specs->width = 0;
	specs->precision = 0;
	specs->lengthmodifier = 0;
	specs->conversion = 0;
	specs->typeindex = -1;
	return (specs);
}

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

int				ft_vprintf(const char *format, va_list args)
{
	t_specs		*specs;
	int			i;

	i = 0;
	while (format[i] != '\0')
	{
		i += print_til_percent(format + i);
		if (format[i] == '%')
		{
			specs = initialize_specs();
			i += fill_specs(format + i, specs, args);
			print_arg(args, specs);
		}
		else if (format[i] != '\0')
			i++;
	}
	return (i);
}

int				ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	va_start(args, format);
	count = ft_vprintf(format, args);
	va_end(args);

	return (count);
}
