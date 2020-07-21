/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:57:26 by seimori           #+#    #+#             */
/*   Updated: 2020/07/21 18:58:29 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "../includes/libft.h"

void		free_get_next_line(t_buffer *buffer_head)
{
	t_buffer	*buffer;

	while (buffer_head->next)
	{
		buffer = buffer_head;
		buffer_head = buffer_head->next;
		free(buffer->str);
		free(buffer);
	}
	free(buffer_head->str);
	free(buffer_head);
}
