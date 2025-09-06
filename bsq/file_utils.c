/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*expand_read_buffer(t_read *data, int bytes)
{
	char	*new_buffer;

	new_buffer = allocate_expanded_buffer(data, bytes);
	if (!new_buffer)
		return (NULL);
	copy_to_buffer(new_buffer, data->content, data->total_size);
	free(data->content);
	return (new_buffer);
}

void	copy_to_buffer(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

int	read_chunk(int fd, char *buffer)
{
	return (read(fd, buffer, BUFFER_SIZE));
}

char	*allocate_expanded_buffer(t_read *data, int bytes)
{
	int		new_size;
	char	*new_buffer;

	new_size = data->total_size + bytes + 1;
	new_buffer = malloc(new_size);
	return (new_buffer);
}

void	update_read_data(t_read *data, char *new_buf, int bytes)
{
	data->content = new_buf;
	data->total_size += bytes;
	data->content[data->total_size] = '\0';
}
