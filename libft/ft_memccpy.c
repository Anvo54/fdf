/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:42:23 by avornane          #+#    #+#             */
/*   Updated: 2019/10/25 11:23:11 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cpy;
	unsigned char	*src_copy;
	size_t			i;

	cpy = (unsigned char*)dst;
	src_copy = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		cpy[i] = src_copy[i];
		if (src_copy[i] == (unsigned char)c)
			return ((void*)dst + i + 1);
		i++;
	}
	return (NULL);
}
