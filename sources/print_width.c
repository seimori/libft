/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:08:13 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/10 14:49:38 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void		print_width(t_arg arg, t_specs *specs)
{
	int		i;
	char	fill_char;
	int		arg_len;

	i = 0;
	fill_char = ' ';
	arg_len = get_arg_len(arg, specs);
	while ((specs->width - arg_len) - i > 0)
	{
		ft_putchar(fill_char);
		i++;
	}
}
