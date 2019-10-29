/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:27:26 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/29 23:31:21 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				is_flag(char c)
{
	return (c == '#' || c == '0' || c == '-' ||
			c == '+' || c == ' ');
}

int				is_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == '%' ||
			c == 'd' || c == 'i' || c == 'o' || c == 'u' ||
			c == 'x' || c == 'X' || c == 'f');
}

int				is_hex_or_octal(t_specs *specs)
{
	return (specs->conversion == 'x' || specs->conversion == 'X'
			|| specs->conversion == 'o' || specs->conversion == 'p');
}
