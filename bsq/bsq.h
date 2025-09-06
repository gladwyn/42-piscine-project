/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 4096

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_map;

typedef struct s_square
{
	int	row;
	int	col;
	int	size;
}	t_square;

typedef struct s_read
{
	char	*content;
	int		total_size;
	int		capacity;
}	t_read;

/* main.c */
int			main(int argc, char **argv);
void		process_files(int argc, char **argv);
void		process_stdin(void);
void		handle_file(char *filename, int is_last);
void		print_newline_if_needed(int is_last);

/* file_read.c */
char		*read_file_content(char *filename);
int			open_file_descriptor(char *filename);
void		init_read_data(t_read *data);
int			read_file_loop(int fd, t_read *data);
void		close_file_if_needed(char *filename, int fd);

/* file_utils.c */
char		*expand_read_buffer(t_read *data, int bytes);
void		copy_to_buffer(char *dest, char *src, int size);
int			read_chunk(int fd, char *buffer);
char		*allocate_expanded_buffer(t_read *data, int bytes);
void		update_read_data(t_read *data, char *new_buf, int bytes);

/* string_utils.c */
int			ft_strlen(char *str);
char		*ft_strdup(char *src);
void		ft_putstr_fd(char *str, int fd);
int			is_printable_char(char c);
void		copy_string_chars(char *dest, char *src, int len);

/* line_split.c */
char		**split_content_to_lines(char *content, int *count);
int			count_newlines_in_content(char *content);
char		**allocate_lines_array(int line_count);
void		extract_lines_from_content(char **lines, char *content);
char		*extract_single_line(char *content, int start, int end);

/* map_parse.c */
t_map		*parse_map_from_file(char *filename);
int			parse_map_first_line(char *line, t_map *map);
t_map		*create_map_structure(char **lines, int count);
int			setup_map_from_lines(t_map *map, char **lines, int count);
void		cleanup_lines_array(char **lines, int count);

/* map_setup.c */
int			parse_number_from_line(char *line, int *pos);
int			extract_map_characters(char *line, t_map *map);
int			validate_map_characters(t_map *map);
int			are_characters_unique(char empty, char obs, char full);
int			allocate_map_grid(t_map *map);

/* map_fill.c */
int			fill_map_with_data(t_map *map, char **lines, int count);
int			check_sufficient_lines(int count, int needed);
int			copy_line_to_grid(t_map *map, char *line, int row);
void		cleanup_partial_grid(t_map *map, int up_to_row);
int			validate_filled_map(t_map *map);

/* map_validate.c */
int			validate_map_dimensions(t_map *map);
int			validate_all_line_lengths(t_map *map);
int			validate_map_characters_only(t_map *map);
int			check_line_characters(t_map *map, int row);
void		free_complete_map(t_map *map);

/* solver.c */
t_square	find_largest_square(t_map *map);
int			**create_dp_table(t_map *map);
void		fill_dp_table(t_map *map, int **dp);
t_square	find_max_in_dp_table(int **dp, t_map *map);
void		free_dp_table(int **dp, int rows);

/* dp_utils.c */
int			**allocate_dp_matrix(int rows, int cols);
void		initialize_dp_matrix(int **dp, int rows, int cols);
void		fill_dp_first_row(t_map *map, int **dp);
void		fill_dp_first_col(t_map *map, int **dp);
int			calculate_dp_cell(t_map *map, int **dp, int i, int j);

/* dp_calc.c */
void		process_dp_rows(t_map *map, int **dp);
void		process_dp_single_row(t_map *map, int **dp, int row);
int			get_minimum_of_three(int a, int b, int c);
int			is_cell_obstacle(t_map *map, int row, int col);
void		cleanup_dp_matrix(int **dp, int rows);

/* square_find.c */
t_square	search_for_max_square(int **dp, t_map *map);
void		init_square_result(t_square *square);
void		check_dp_cell_for_max(int **dp, t_square *sq, int i, int j);
void		update_square_if_larger(t_square *sq, int size, int i, int j);
t_square	calculate_square_position(int size, int end_i, int end_j);

/* output.c */
void		write_solution(t_map *map, t_square sq, char *filename);
void		fill_square_area(t_map *map, t_square square);
void		print_map_stdout(t_map *map);
void		write_map_to_file(t_map *map, int fd);
int			open_output_file(char *filename);

#endif
