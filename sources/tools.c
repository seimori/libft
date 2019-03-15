/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:10:59 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/11 18:23:04 by imorimot         ###   ########.fr       */
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
		if (!(s = (char*)malloc(temp_len + 1 + 1)))
			return (NULL);
		ft_strcpy(s, temp);
		s[temp_len] = c;
		s[temp_len + 1] = '\0';
		free(temp);
	}
	return (s);
}
