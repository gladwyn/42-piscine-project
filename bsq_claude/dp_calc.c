/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	process_dp_rows(t_map *map, int **dp)
{
	int	i;

	i = 1;
	while (i < map->rows)
	{
		process_dp_single_row(map, dp, i);
		i++;
	}
}

void	process_dp_single_row(t_map *map, int **dp, int row)
{
	int	j;

	j = 1;
	while (j < map->cols)
	{
		dp[row][j] = calculate_dp_cell(map, dp, row, j);
		j++;
	}
}

int	get_minimum_of_three(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

int	is_cell_obstacle(t_map *map, int row, int col)
{
	if (map->grid[row][col] == map->obstacle)
		return (1);
	return (0);
}

void	cleanup_dp_matrix(int **dp, int rows)
{
	int	i;

	if (!dp)
		return ;
	i = 0;
	while (i < rows)
	{
		if (dp[i])
			free(dp[i]);
		i++;
	}
	free(dp);
}
