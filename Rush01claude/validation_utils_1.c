typedef struct s_position {
	int row;
	int col;
	int num;
	int size;
} t_position;

int		is_valid_position(int **grid, t_position pos)
{
	int	i;

	i = 0;
	while (i < pos.size)
	{
		if (grid[pos.row][i] == pos.num || grid[i][pos.col] == pos.num)
			return (0);
		i++;
	}
	return (1);
}

int		count_visible_forward(int *line, int size)
{
	int	count;
	int	max;
	int	i;

	count = 1;
	max = line[0];
	i = 1;
	while (i < size)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int		count_visible_backward(int *line, int size)
{
	int	count;
	int	max;
	int	i;

	count = 1;
	max = line[size - 1];
	i = size - 2;
	while (i >= 0)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i--;
	}
	return (count);
}