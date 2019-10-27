/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:10:59 by imorimot          #+#    #+#             */
/*   Updated: 2019/10/27 18:57:23 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char			*ft_str_append(char *s, char c)
{
	char		*temp;
	int			temp_len;

	if (!s)
	{
		s = ft_strnew(1);
		s[0] = c;
		s[1] = '\0';
	}
	else
	{
		temp = s;
		temp_len = ft_strlen(temp);
		s = ft_memalloc(temp_len + 1 + 1);
		ft_strcpy(s, temp);
		s[temp_len] = c;
		s[temp_len + 1] = '\0';
		free(temp);
	}
	return (s);
}

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
