/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**split_content_to_lines(char *content, int *count)
{
	char	**lines;
	int		line_count;

	line_count = count_newlines_in_content(content);
	lines = allocate_lines_array(line_count);
	if (!lines)
		return (NULL);
	*count = line_count;
	extract_lines_from_content(lines, content);
	return (lines);
}

int	count_newlines_in_content(char *content)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	**allocate_lines_array(int line_count)
{
	return (malloc(sizeof(char *) * (line_count + 1)));
}

void	extract_lines_from_content(char **lines, char *content)
{
	int	line_idx;
	int	i;
	int	start;

	line_idx = 0;
	i = 0;
	start = 0;
	while (content[i])
	{
		if (content[i] == '\n')
		{
			lines[line_idx] = extract_single_line(content, start, i);
			line_idx++;
			start = i + 1;
		}
		i++;
	}
}

char	*extract_single_line(char *content, int start, int end)
{
	char	*line;
	int		len;

	len = end - start;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	copy_to_buffer(line, content + start, len);
	line[len] = '\0';
	return (line);
}
