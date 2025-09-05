/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		process_stdin();
	else
		process_files(argc, argv);
	return (0);
}

void	process_files(int argc, char **argv)
{
	int	i;
	int	is_last;

	i = 1;
	while (i < argc)
	{
		is_last = (i == argc - 1);
		handle_file(argv[i], is_last);
		i++;
	}
}

void	process_stdin(void)
{
	t_map		*map;
	t_square	square;

	map = parse_map_from_file(NULL);
	if (!map)
	{
		ft_putstr_fd("map error\n", 2);
		return ;
	}
	square = find_largest_square(map);
	fill_square_area(map, square);
	print_map_stdout(map);
	free_complete_map(map);
}

void	handle_file(char *filename, int is_last)
{
	t_map		*map;
	t_square	square;

	map = parse_map_from_file(filename);
	if (!map)
	{
		ft_putstr_fd("map error\n", 2);
		print_newline_if_needed(is_last);
		return ;
	}
	square = find_largest_square(map);
	write_solution(map, square, filename);
	print_newline_if_needed(is_last);
	free_complete_map(map);
}

void	print_newline_if_needed(int is_last)
{
	if (!is_last)
		write(1, "\n", 1);
}
