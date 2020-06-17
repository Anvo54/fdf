/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:36:13 by avornane          #+#    #+#             */
/*   Updated: 2019/10/28 12:37:29 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*value;

	value = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			value = (char*)s;
		}
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char*)s);
	return (value);
}
