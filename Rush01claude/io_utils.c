#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_grid_row(int **grid, int size, int row)
{
	int	j;

	j = 0;
	while (j < size)
	{
		ft_putchar(grid[row][j] + '0');
		if (j < size - 1)
			ft_putchar(' ');
		j++;
	}
	ft_putchar('\n');
}

void	print_grid(int **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		print_grid_row(grid, size, i);
		i++;
	}
}