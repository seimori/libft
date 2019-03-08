/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:26:28 by imorimot          #+#    #+#             */
/*   Updated: 2018/11/26 19:59:32 by imorimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(*src) * (ft_strlen(src) + 1))))
		return (0);
	ft_strcpy(str, src);
	return (str);
}
