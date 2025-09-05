int count_visible_forward(int *line, int size); 
int count_visible_backward(int *line, int size);

int		check_row_views(int **grid, int *views, int size, int row)
{
	int	j;
	int	row_arr[size];

	j = 0;
	while (j < size)
	{
		row_arr[j] = grid[row][j];
		j++;
	}
	if (count_visible_forward(row_arr, size) != views[size * 2 + row])
		return (0);
	if (count_visible_backward(row_arr, size) != views[size * 3 + row])
		return (0);
	return (1);
}

int		check_col_views(int **grid, int *views, int size, int col)
{
	int	i;
	int	col_arr[size];

	i = 0;
	while (i < size)
	{
		col_arr[i] = grid[i][col];
		i++;
	}
	if (count_visible_forward(col_arr, size) != views[col])
		return (0);
	if (count_visible_backward(col_arr, size) != views[size + col])
		return (0);
	return (1);
}

int		check_views(int **grid, int *views, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!check_row_views(grid, views, size, i))
			return (0);
		if (!check_col_views(grid, views, size, i))
			return (0);
		i++;
	}
	return (1);
}