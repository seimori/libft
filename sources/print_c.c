/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:01:09 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/07 19:28:41 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
void			print_width(t_specs *specs)
{
	int		i;
	int		char_length;
	char	fill_char;

	i = 0;
	char_length = 1;
	fill_char = ' ';
	if (specs->flags & ZERO)
		fill_char = '0';
	while ((specs->width - char_length) - i > 0)
	{
		ft_putchar(fill_char);
		i++;
	}
}
*/

void			print_c(t_arg arg, t_specs *specs)
{
	(void)specs;
	ft_putchar(arg.c);
}
