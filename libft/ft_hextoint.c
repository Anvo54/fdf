/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:33:12 by avornane          #+#    #+#             */
/*   Updated: 2020/06/08 16:57:53 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int			has_prefix(char *s)
{
	return ((s[0] == '0' && s[1] == 'x') || (s[0] == '0' && s[1] == 'X'));
}

int			ft_hextoint(char *s)
{
	int		sign;
	int		result;
	int		i;

	i = 0;
	result = 0;
	while (ft_isblank(*s))
		s++;
	sign = (*s == '-') ? -1 : 1;
	(*s == '-' || *s == '+') ? s++ : 0;
	(has_prefix(s)) ? i += 2 : 0;
	while (s[i])
	{
		result = result * 16 + s[i] - 55;
		i++;
	}
	return (result);
}
