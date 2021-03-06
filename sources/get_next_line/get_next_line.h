/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seimori <seimori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:45:26 by imorimot          #+#    #+#             */
/*   Updated: 2020/07/21 18:58:42 by seimori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42
# define LINE_SIZE 4086

typedef struct			s_buffer
{
	int					fd;
	char				*str;
	struct s_buffer		*next;
}						t_buffer;

int						get_next_line(const int fd, char **line);
void					free_get_next_line(t_buffer *buffer_head);

#endif
