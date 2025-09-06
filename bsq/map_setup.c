
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	parse_number_from_line(char *line, int *pos)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		result = result * 10 + (line[i] - '0');
		i++;
	}
	*pos = i;
	return (result);
}

int	extract_map_characters(char *line, t_map *map)
{
	int	len;

	len = ft_strlen(line);
	map->empty = line[len - 3];
	map->obstacle = line[len - 2];
	map->full = line[len - 1];
	return (validate_map_characters(map));
}

int	validate_map_characters(t_map *map)
{
	if (!are_characters_unique(map->empty, map->obstacle, map->full))
		return (0);
	if (!is_printable_char(map->empty))
		return (0);
	if (!is_printable_char(map->obstacle))
		return (0);
	if (!is_printable_char(map->full))
		return (0);
	return (1);
}

int	are_characters_unique(char empty, char obs, char full)
{
	if (empty == obs)
		return (0);
	if (empty == full)
		return (0);
	if (obs == full)
		return (0);
	return (1);
}

int	allocate_map_grid(t_map *map)
{
	map->grid = malloc(sizeof(char *) * map->rows);
	if (!map->grid)
		return (0);
	return (1);
}