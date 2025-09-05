/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gltay <gltay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:27:18 by gltay             #+#    #+#             */
/*   Updated: 2025/07/27 09:29:21 by gltay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush03(int x, int y)
{
	int	row;
	int	column;

	row = 1;
	while (row <= y)
	{
		column = 1;
		while (column <= x)
		{
			if ((column > 1 && column < x) && (row > 1 && row < y))
				ft_putchar(' ');
			else if ((column > 1 && column < x) && (row == 1 || row == y))
				ft_putchar('B');
			else if ((column == 1 || column == x) && (row > 1 && row < y))
				ft_putchar('B');
			else if ((column == 1 && row == 1) || (column == 1 && row == y))
				ft_putchar('A');
			else if ((column == x && row == 1) || (column == x && row == y))
				ft_putchar('C');
			column++;
		}
		ft_putchar ('\n');
		row++;
	}
}
