/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	write_solution(t_map *map, t_square sq, char *filename)
{
	int	fd;

	fill_square_area(map, sq);
	if (filename)
	{
		fd = open_output_file(filename);
		if (fd == -1)
		{
			print_map_stdout(map);
			return ;
		}
		write_map_to_file(map, fd);
		close(fd);
	}
	print_map_stdout(map);
}

void	fill_square_area(t_map *map, t_square square)
{
	int	i;
	int	j;

	i = square.row;
	while (i < square.row + square.size)
	{
		j = square.col;
		while (j < square.col + square.size)
		{
			map->grid[i][j] = map->full;
			j++;
		}
		i++;
	}
}

void	print_map_stdout(t_map *map)
{
	write_map_to_file(map, 1);
}

void	write_map_to_file(t_map *map, int fd)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		write(fd, map->grid[i], map->cols);
		write(fd, "\n", 1);
		i++;
	}
}

int	open_output_file(char *filename)
{
	return (open(filename, O_WRONLY | O_TRUNC));
}