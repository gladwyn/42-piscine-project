/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiyahaya <aiyahaya@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:46:49 by aiyahaya          #+#    #+#             */
/*   Updated: 2025/08/10 22:30:13 by aiyahaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*g_ones[10] = {"zero", "one", "two", "three", "four",
	"five", "six", "seven", "eight", "nine"};
char	*g_tens[10] = {"", "ten", "twenty", "thirty", "forty", "fifty",
	"sixty", "seventy", "eighty", "ninety"};
char	*g_teens[10] = {"ten", "eleven", "tweleve", "thirteen", "forteen",
	"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char	*g_expo[13] = {"", "thousand", "million", "billion",
	"trillion", "quadrillion", "quintillion", "sextillion",
	"septillion", "octillion", "nonillion", "decillion",
	"unedecillion"};


int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

void	write_nums(char c, char *num_list[10])
{
	char	*digits;
	char	*num;
	int		len;
	int		i;

	digits = "0123456789";
	i = 0;
	while (digits[i])
	{
		if (digits[i] == c)
			break ;
		i++;
	}
	num = num_list[i];
	len = ft_strlen(num);
	write(1, num, len);
}

void	write_expo(int x)
{
	char	*num;
	int		len;

	num = g_expo[x / 3];
	len = ft_strlen(num);
	write(1, num, len);
	write(1, " ", 1);
}

void	write_numbers(char *str, int len)
{
	int		i;

	i = 0;
	while (len)
	{
		if (i > 0 && len % 3 == 0)
			write_expo(len);
		if (len % 3 == 2 && str[i] == '1')
			write_nums(str[i + 1], g_teens);
		else if (len % 3 == 2)
			write_nums(str[i], g_tens);
		else if (i > 0 && len % 3 == 1 && (str[i] == '0' || str[i - 1] == '1'))
		{
			len --;
			i++;
			continue ;
		}
		else
			write_nums(str[i], g_ones);
		if (len % 3 == 0)
			write(1, " hundred", 9);
		if (len > 1)
			write(1, " ", 1);
		len --;
		i++;
	}
}

/* int main(void)
{
	write_numbers("0", 1);
	write(1, "\n", 1);
	write_numbers("42", 2);
	write(1, "\n", 1);
	write_numbers("12", 2);
	write(1, "\n", 1);
	write_numbers("150", 3);
	write(1, "\n", 1);
	write_numbers("210", 3);
	write(1, "\n", 1);
} */
