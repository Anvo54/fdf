int ft_count_char(char *str, char c)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			result++;
			while (str[i] == c)
				i++;
		}
		i++;
	}
	return(result);
}