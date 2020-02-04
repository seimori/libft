/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:39:09 by imorimot          #+#    #+#             */
/*   Updated: 2019/03/09 17:07:08 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char			*c_src;
	char			*c_dst;
	unsigned char	uc_c;

	i = 0;
	c_src = (char*)src;
	c_dst = (char*)dst;
	uc_c = (unsigned char)c;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		if ((unsigned char)c_src[i] == uc_c)
<<<<<<< HEAD
			return (&dst[i + 1]);
=======
			return (dst + i + 1);
>>>>>>> fabc428a3ab11a356757706c6375ecc610678aab
		i++;
	}
	return (NULL);
}
