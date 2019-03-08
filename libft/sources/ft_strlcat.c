/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:41:50 by imorimot          #+#    #+#             */
/*   Updated: 2018/11/15 17:35:03 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	start_len;

	i = 0;
	start_len = ft_strlen(dst);
	if (size <= start_len)
		return (ft_strlen(src) + size);
	else
	{
		while (i < size - start_len - 1 && src[i] != '\0')
		{
			dst[i + start_len] = src[i];
			i++;
		}
		dst[i + start_len] = '\0';
		return (ft_strlen(src) + start_len);
	}
}
