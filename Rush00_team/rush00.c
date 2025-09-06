/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gltay <gltay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:27:18 by gltay             #+#    #+#             */
/*   Updated: 2025/07/27 09:25:52 by gltay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
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
				ft_putchar('-');
			else if ((column == 1 || column == x) && (row > 1 && row < y))
				ft_putchar('|');
			else if ((column == 1 && row == 1) || (column == x && row == y))
				ft_putchar('o');
			else if ((column == 1 && row == y) || (column == x && row == 1))
				ft_putchar('o');
			column++;
		}
		ft_putchar ('\n');
		row++;
	}
}
