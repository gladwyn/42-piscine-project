/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	validate_map_dimensions(t_map *map)
{
	if (map->rows <= 0)
		return (0);
	map->cols = ft_strlen(map->grid[0]);
	if (map->cols <= 0)
		return (0);
	if (!validate_all_line_lengths(map))
		return (0);
	return (validate_map_characters_only(map));
}

int	validate_all_line_lengths(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (ft_strlen(map->grid[i]) != map->cols)
			return (0);
		i++;
	}
	return (1);
}

int	validate_map_characters_only(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (!check_line_characters(map, i))
			return (0);
		i++;
	}
	return (1);
}

int	check_line_characters(t_map *map, int row)
{
	int	j;

	j = 0;
	while (j < map->cols)
	{
		if (map->grid[row][j] != map->empty
			&& map->grid[row][j] != map->obstacle)
			return (0);
		j++;
	}
	return (1);
}

void	free_complete_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->rows)
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
}
