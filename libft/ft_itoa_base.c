#include "libft.h"

char			*ft_itoa_base(int value, int base)
{
	long	n;
	int		sign;
	int		i;
	char 	*result;

	n = (value < 0) ? -(long)value : value;
	sign = (n < 0 && base == 10) ? '-' : 0;
	i = (sign == '-') ? 1 : 0;
	while ((n % base) >= 1)
	{
		n /= base;
		i++;
	}
	n = (value < 0) ? -(long)value : value;
	result = (char*)malloc(i * sizeof(char));
	while (i-- + sign)
	{
		result[i] = (n % base > 10) ? n % base + 55: n % base + 65;
		n /= base;
	}
	if (i == 0)
		result[i] = '-';
	return(result);
}