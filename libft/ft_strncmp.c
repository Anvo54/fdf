/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:03:58 by avornane          #+#    #+#             */
/*   Updated: 2019/10/28 14:07:33 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && n > 1)
	{
		s1++;
		s2++;
		n--;
	}
	if (*(unsigned char *)s1 < *(unsigned char *)s2)
		return (-1);
	if (*(unsigned char *)s1 == *(unsigned char *)s2)
		return (0);
	else
		return (1);
}
