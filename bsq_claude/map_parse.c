
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map	*parse_map_from_file(char *filename)
{
	char	*content;
	char	**lines;
	int		line_count;
	t_map	*map;

	content = read_file_content(filename);
	if (!content)
		return (NULL);
	lines = split_content_to_lines(content, &line_count);
	free(content);
	if (!lines || line_count < 2)
	{
		if (lines)
			cleanup_lines_array(lines, line_count);
		return (NULL);
	}
	map = create_map_structure(lines, line_count);
	cleanup_lines_array(lines, line_count);
	return (map);
}

int	parse_map_first_line(char *line, t_map *map)
{
	int	len;
	int	pos;

	len = ft_strlen(line);
	if (len < 4)
		return (0);
	pos = 0;
	map->rows = parse_number_from_line(line, &pos);
	if (map->rows <= 0 || pos != len - 3)
		return (0);
	return (extract_map_characters(line, map));
}

t_map	*create_map_structure(char **lines, int count)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	if (!parse_map_first_line(lines[0], map))
	{
		free(map);
		return (NULL);
	}
	if (!setup_map_from_lines(map, lines, count))
	{
		free_complete_map(map);
		return (NULL);
	}
	return (map);
}

int	setup_map_from_lines(t_map *map, char **lines, int count)
{
	if (!allocate_map_grid(map))
		return (0);
	if (!fill_map_with_data(map, lines, count))
		return (0);
	return (validate_filled_map(map));
}

void	cleanup_lines_array(char **lines, int count)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (i < count)
	{
		if (lines[i])
			free(lines[i]);
		i++;
	}
	free(lines);
}
