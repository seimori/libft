/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:07:06 by imorimot          #+#    #+#             */
/*   Updated: 2018/11/23 12:13:32 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	c_char;
	unsigned char	*p;

	i = 0;
	c_char = (unsigned char)c;
	p = b;
	while (i < len)
	{
		p[i] = c_char;
		i++;
	}
	return (p);
}
