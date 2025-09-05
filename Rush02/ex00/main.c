/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiyahaya <aiyahaya@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:10:32 by aiyahaya          #+#    #+#             */
/*   Updated: 2025/08/10 22:30:16 by aiyahaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	validate_arg(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			len ++;
		else
			return (-1);
		i ++;
	}
	return (len);
}

void	write_numbers(char *str, int len);

/* TODO:
 - Parse dict file
 - Pass dict values to print functions
 */

int	main(int argc, char *argv[])
{
	int	len;

	if (argc == 2)
	{
		len = validate_arg(argv[1]);
		if (len > 0)
			write_numbers(argv[1], len);
		else
			write(1, "Error\n", 6);
	}
	else if (argc == 3)
	{
		write(1, "Error\n", 6);
	}
	else
	{
		write(1, "Error\n", 6);
	}
	return (0);
}

/* //sample tests:
int	main(void)
{
	write_numbers("0", 2);
	write(1, "\n", 1);
	write_numbers("42", 2);
	write(1, "\n", 1);
	write_numbers("12", 2);
	write(1, "\n", 1);
	write_numbers("416312", 6);
	write(1, "\n", 1);
	write_numbers("410310", 6); 
	write(1, "\n", 1);
	write_numbers("150", 3); 
	write(1, "\n", 1);
	write_numbers("987654321", 9);
	write(1, "\n", 1);
	return (0);
} */
