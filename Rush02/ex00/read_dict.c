/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiyahaya <aiyahaya@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:17:57 by aiyahaya          #+#    #+#             */
/*   Updated: 2025/08/10 21:26:35 by aiyahaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "dict.h"

void	read_file(char *filepath)
{
	int		file;
	char	*buffer;
	ssize_t	bytes_read;

	file = open(filepath, O_RDONLY);
	if (file)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes_read = read(file, buffer, BUFFER_SIZE);
		while (bytes_read > 0)
		{
			buffer[bytes_read] = "\0";
			bytes_read = read(file, buffer, BUFFER_SIZE);
		}
		close(file);
		free(buffer);
	}
}

void	process_buffer(char *buffer)
{
	char	*line;
	char	**lines;
	int		count;
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (buffer[i])
	{
		if (buffer[i] == "\n")
		{
			l = 0;
		}
		else
		{
			line[l] = buffer[i];
			l++;
		}
		i++;
	}
}

int	main(void)
{
	read_file("numbers.dict");
}
