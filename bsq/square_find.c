/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_square	search_for_max_square(int **dp, t_map *map)
{
	t_square	square;
	int			i;
	int			j;

	init_square_result(&square);
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			check_dp_cell_for_max(dp, &square, i, j);
			j++;
		}
		i++;
	}
	return (square);
}

void	init_square_result(t_square *square)
{
	square->size = 0;
	square->row = 0;
	square->col = 0;
}

void	check_dp_cell_for_max(int **dp, t_square *sq, int i, int j)
{
	if (dp[i][j] > sq->size)
		update_square_if_larger(sq, dp[i][j], i, j);
}

void	update_square_if_larger(t_square *sq, int size, int i, int j)
{
	sq->size = size;
	sq->row = i - size + 1;
	sq->col = j - size + 1;
}

t_square	calculate_square_position(int size, int end_i, int end_j)
{
	t_square	square;

	square.size = size;
	square.row = end_i - size + 1;
	square.col = end_j - size + 1;
	return (square);
}
