

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	fill_map_with_data(t_map *map, char **lines, int count)
{
	int	i;

	if (!check_sufficient_lines(count, map->rows + 1))
		return (0);
	i = 0;
	while (i < map->rows)
	{
		if (!copy_line_to_grid(map, lines[i + 1], i))
		{
			cleanup_partial_grid(map, i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_sufficient_lines(int count, int needed)
{
	if (count < needed)
		return (0);
	return (1);
}

int	copy_line_to_grid(t_map *map, char *line, int row)
{
	map->grid[row] = ft_strdup(line);
	if (!map->grid[row])
		return (0);
	return (1);
}

void	cleanup_partial_grid(t_map *map, int up_to_row)
{
	int	i;

	i = 0;
	while (i < up_to_row)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

int	validate_filled_map(t_map *map)
{
	return (validate_map_dimensions(map));
}