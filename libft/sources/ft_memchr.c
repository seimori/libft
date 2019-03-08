/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:13:24 by imorimot          #+#    #+#             */
/*   Updated: 2018/11/22 12:34:25 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*uc_s;
	unsigned char		uc_c;

	i = 0;
	uc_s = (unsigned char*)s;
	uc_c = (unsigned char)c;
	while (i < n)
	{
		if (uc_s[i] == uc_c)
			return ((void*)&uc_s[i]);
		i++;
	}
	return (NULL);
}
