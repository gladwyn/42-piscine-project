/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**allocate_dp_matrix(int rows, int cols)
{
	int	**dp;
	int	i;

	dp = malloc(sizeof(int *) * rows);
	if (!dp)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		dp[i] = malloc(sizeof(int) * cols);
		if (!dp[i])
		{
			cleanup_dp_matrix(dp, i);
			return (NULL);
		}
		i++;
	}
	return (dp);
}

void	initialize_dp_matrix(int **dp, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			dp[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	fill_dp_first_row(t_map *map, int **dp)
{
	int	j;

	j = 0;
	while (j < map->cols)
	{
		if (is_cell_obstacle(map, 0, j))
			dp[0][j] = 0;
		else
			dp[0][j] = 1;
		j++;
	}
}

void	fill_dp_first_col(t_map *map, int **dp)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (is_cell_obstacle(map, i, 0))
			dp[i][0] = 0;
		else
			dp[i][0] = 1;
		i++;
	}
}

int	calculate_dp_cell(t_map *map, int **dp, int i, int j)
{
	int	min_val;

	if (is_cell_obstacle(map, i, j))
		return (0);
	min_val = get_minimum_of_three(dp[i - 1][j], dp[i][j - 1],
			dp[i - 1][j - 1]);
	return (min_val + 1);
}
