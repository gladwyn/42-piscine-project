#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str);
int		is_valid_input(char *str, int *size);
void	parse_input(char *str, int *views, int size);
int		solve(int **grid, int *views, int size);
void	print_grid(int **grid, int size);

int	initialize_grid(int ***grid, int size)
{
	int	i;

	*grid = (int **)malloc(sizeof(int *) * size);
	if (!*grid)
		return (0);
	i = 0;
	while (i < size)
	{
		(*grid)[i] = (int *)malloc(sizeof(int) * size);
		if (!(*grid)[i])
			return (0);
		i++;
	}
	return (1);
}

void	cleanup_resources(int **grid, int *views, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	free(views);
}

int		main(int argc, char **argv)
{
	int	size;
	int	*views;
	int	**grid;

	if (argc != 2 || !is_valid_input(argv[1], &size))
	{
		ft_putstr("Error\n");
		return (1);
	}
	views = (int *)malloc(sizeof(int) * size * 4);
	if (!views || !initialize_grid(&grid, size))
	{
		ft_putstr("Error\n");
		free(views);
		return (1);
	}
	parse_input(argv[1], views, size);
	if (solve(grid, views, size))
		print_grid(grid, size);
	else
		ft_putstr("Error\n");
	cleanup_resources(grid, views, size);
	return (0);
}