/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_square	find_largest_square(t_map *map)
{
	int			**dp;
	t_square	square;

	dp = create_dp_table(map);
	if (!dp)
	{
		square.row = 0;
		square.col = 0;
		square.size = 0;
		return (square);
	}
	fill_dp_table(map, dp);
	square = find_max_in_dp_table(dp, map);
	free_dp_table(dp, map->rows);
	return (square);
}

int	**create_dp_table(t_map *map)
{
	int	**dp;

	dp = allocate_dp_matrix(map->rows, map->cols);
	if (!dp)
		return (NULL);
	initialize_dp_matrix(dp, map->rows, map->cols);
	return (dp);
}

void	fill_dp_table(t_map *map, int **dp)
{
	fill_dp_first_row(map, dp);
	fill_dp_first_col(map, dp);
	process_dp_rows(map, dp);
}

t_square	find_max_in_dp_table(int **dp, t_map *map)
{
	return (search_for_max_square(dp, map));
}

void	free_dp_table(int **dp, int rows)
{
	cleanup_dp_matrix(dp, rows);
}
