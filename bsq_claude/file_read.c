

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*read_file_content(char *filename)
{
	int		fd;
	t_read	data;
	int		success;

	fd = open_file_descriptor(filename);
	if (fd == -1)
		return (NULL);
	init_read_data(&data);
	if (!data.content)
	{
		close_file_if_needed(filename, fd);
		return (NULL);
	}
	success = read_file_loop(fd, &data);
	close_file_if_needed(filename, fd);
	if (!success)
	{
		free(data.content);
		return (NULL);
	}
	return (data.content);
}

int	open_file_descriptor(char *filename)
{
	if (filename)
		return (open(filename, O_RDONLY));
	return (0);
}

void	init_read_data(t_read *data)
{
	data->content = malloc(1);
	data->total_size = 0;
	data->capacity = 0;
	if (data->content)
		data->content[0] = '\0';
}

int	read_file_loop(int fd, t_read *data)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	char	*new_content;

	while (1)
	{
		bytes_read = read_chunk(fd, buffer);
		if (bytes_read <= 0)
			break ;
		new_content = expand_read_buffer(data, bytes_read);
		if (!new_content)
			return (0);
		update_read_data(data, new_content, bytes_read);
		copy_to_buffer(data->content + data->total_size - bytes_read,
			buffer, bytes_read);
	}
	return (1);
}

void	close_file_if_needed(char *filename, int fd)
{
	if (filename)
		close(fd);
}
