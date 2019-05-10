/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:25:29 by imorimot          #+#    #+#             */
/*   Updated: 2019/05/10 13:55:44 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				fill_flags(const char *s, t_specs *specs)
{
	int			i;

	i = 0;
	while (is_flag(s[i]))
	{
		if (s[i] == '-')
			specs->flags |= MINUS;
		if (s[i] == '+')
			specs->flags |= PLUS;
		if (s[i] == ' ')
			specs->flags |= SPACE;
		if (s[i] == '0')
			specs->flags |= ZERO;
		if (s[i] == '#')
			specs->flags |= HASH;
		i++;
	}
	return (i);
}

int				fill_width(const char *s, t_specs *specs, va_list args)
{
	int			i;

	i = 0;
	if (s[i] == '*')
	{
		specs->width = va_arg(args, int);
		return (i + 1);
	}
	while (ft_isdigit(s[i]))
		i++;
	specs->width = ft_antoi(s, i);
	return (i);
}

int				fill_precision(const char *s, t_specs *specs, va_list args)
{
	int			i;

	i = 0;
	if (s[i] == '.')
	{
		i++;
		if (s[i] == '*')
		{
			specs->precision = va_arg(args, int);
			return (i + 1);
		}
		while (ft_isdigit(s[i]))
				i++;
		specs->precision = ft_antoi(s + 1, i - 1);
	}
	return (i);
}

int				fill_lengthmodifier(const char *s, t_specs *specs)
{
	if (s[0] == 'h')
	{
		if (s[1] == 'h')
		{
			specs->lengthmodifier = ft_strdup("hh");
			return (2);
		}
		specs->lengthmodifier = ft_strdup("h");
		return (1);
	}
	if (s[0] == 'l')
	{
		if (s[1] == 'l')
		{
			specs->lengthmodifier = ft_strdup("ll");
			return (2);
		}
			specs->lengthmodifier = ft_strdup("l");
			return (1);
	}
	if (s[0] == 'L')
	{
		specs->lengthmodifier = ft_strdup("L");
	}
	return (0);
}

int				fill_conversion(char c, t_specs *specs)
{
	if (is_conversion(c))
	{
		specs->conversion = ft_str_append(specs->conversion, c);
		return (1);
	}
	return (0);
}
