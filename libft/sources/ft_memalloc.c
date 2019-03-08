/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:31:04 by imorimot          #+#    #+#             */
/*   Updated: 2018/11/16 12:04:37 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*c_mem;
	size_t	i;

	i = 0;
	if (!(mem = malloc(size)))
		return (NULL);
	c_mem = (char*)mem;
	while (i < size)
	{
		c_mem[i] = 0;
		i++;
	}
	return (mem);
}
