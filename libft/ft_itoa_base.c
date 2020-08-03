/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:00:58 by avornane          #+#    #+#             */
/*   Updated: 2019/11/08 10:30:18 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(int value, int base)
{
	long		n;
	int			sign;
	int			i;
	char		*result;

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
		result[i] = (n % base > 10) ? n % base + 55 : n % base + 65;
		n /= base;
	}
	if (i == 0)
		result[i] = '-';
	return (result);
}
