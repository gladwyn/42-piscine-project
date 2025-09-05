/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gltay <gltay@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 00:00:00 by gltay             #+#    #+#             */
/*   Updated: 2025/08/23 00:00:00 by gltay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush00(int x, int y);
void	rush01(int x, int y);
void	rush02(int x, int y);
void	rush03(int x, int y);
void	rush04(int x, int y);
void	ft_putchar(char c);
void	ft_putstr(char *str);

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

int	ft_atoi(char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	print_usage(void)
{
	ft_putstr("Usage: ./rush [rush_number] [width] [height]\n");
	ft_putstr("       rush_number: 0, 1, 2, 3, or 4\n");
	ft_putstr("       width: positive integer\n");
	ft_putstr("       height: positive integer\n");
	ft_putstr("\nExample: ./rush 0 5 3\n");
}

void	test_all_rushes(int x, int y)
{
	ft_putstr("=== Rush 00 ===\n");
	rush00(x, y);
	ft_putchar('\n');
	
	ft_putstr("=== Rush 01 ===\n");
	rush01(x, y);
	ft_putchar('\n');
	
	ft_putstr("=== Rush 02 ===\n");
	rush02(x, y);
	ft_putchar('\n');
	
	ft_putstr("=== Rush 03 ===\n");
	rush03(x, y);
	ft_putchar('\n');
	
	ft_putstr("=== Rush 04 ===\n");
	rush04(x, y);
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	int	rush_num;
	int	x;
	int	y;

	if (argc == 1)
	{
		ft_putstr("Running default tests...\n\n");
		test_all_rushes(5, 3);
		return (0);
	}
	if (argc == 2 && argv[1][0] == 'h')
	{
		print_usage();
		return (0);
	}
	if (argc != 4)
	{
		ft_putstr("Error: Invalid number of arguments\n");
		print_usage();
		return (1);
	}
	rush_num = ft_atoi(argv[1]);
	x = ft_atoi(argv[2]);
	y = ft_atoi(argv[3]);
	
	if (x <= 0 || y <= 0)
	{
		ft_putstr("Error: Width and height must be positive\n");
		return (1);
	}
	
	if (rush_num == 0)
		rush00(x, y);
	else if (rush_num == 1)
		rush01(x, y);
	else if (rush_num == 2)
		rush02(x, y);
	else if (rush_num == 3)
		rush03(x, y);
	else if (rush_num == 4)
		rush04(x, y);
	else
	{
		ft_putstr("Error: Rush number must be 0, 1, 2, 3, or 4\n");
		return (1);
	}
	return (0);
}
