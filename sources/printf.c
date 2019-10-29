/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:48:38 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/29 18:38:24 by imorimot         ###   ########.fr       */
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
	specs->is_negative = 0;
	specs->is_zero = 0;
	specs->arg_len = 0;
	specs->spaces_len = 0;
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
	int			format_count;
	int			print_count;
	int			temp;
	fp_arg		*print;
	t_specs		*specs;

	format_count = 0;
	print_count = 0;
	temp = 0;
	print = initialize_print_functions();
	while (format[format_count] != '\0')
	{
		temp += print_til_percent(format + format_count);
		format_count += temp;
		print_count += temp;
		temp = 0;
		if (format[format_count] == '%')
		{
			specs = initialize_specs();
			format_count += fill_specs(format + format_count, specs, args);
			if (is_error(specs))
				return (print_count);
			print_count += print_arg(args, specs, print);
			free (specs);
		}
		else if (format[format_count] != '\0')
			format_count++;
	}
	free (print);
	return (print_count);
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
