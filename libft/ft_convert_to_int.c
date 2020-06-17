#include "libft.h"

int ft_convert_to_int(char *str)
{
	int result;
	int sign;
	char *s;

	result = 0;
	s = ft_strdup(str);
	sign = (*s == '-') ? -1 : 1;
	while (!ft_isdigit(*s))
		s++;
	while (ft_isdigit(*s))
	{
		result = result * 10 + *s - '0';
		s++;
	}
	return(result * sign);
}