/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:10:59 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/29 14:42:21 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

#define NULL_LEN 6

int					ft_pow(int n, int pow)
{
	int			i;

	i = 1;
	if (pow == 0)
		return (1);
	while (i < pow)
	{
		n *= n;
		i++;
	}
	return (n);
}

int				ft_antoi(const char *s, int length)
{
	char		*temp;
	int			i;

	temp = ft_strnew(length + 1);
	temp = ft_strncpy(temp, s, length);
	i = ft_atoi(temp);
	free(temp);
	return (i);
}

void			ft_putstrn(const char *s, int length)
{
	int			i;

	i = 0;
	while (i < length)
	{
		ft_putchar(s[i]);
		i++;
	}
}

int				print_null(void)
{
	ft_putstr("(null)");
	return (NULL_LEN);
}

int				is_error(t_specs *specs)
{
			return (!(is_conversion(specs->conversion)));
}
