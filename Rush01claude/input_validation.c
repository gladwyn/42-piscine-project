int		count_digits(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			count++;
		else if (str[i] != ' ')
			return (-1);
		i++;
	}
	return (count);
}

int		is_valid_input(char *str, int *size)
{
	int	count;

	count = count_digits(str);
	if(count % 4 == 0 && count > 0)
		*size = count / 4;
	else
		return (0);
	return (1);
}

void	parse_input(char *str, int *views, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && j < size * 4)
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			views[j] = str[i] - '0';
			j++;
		}
		i++;
	}
}