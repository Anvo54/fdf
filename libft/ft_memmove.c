/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:05:17 by avornane          #+#    #+#             */
/*   Updated: 2019/11/04 16:56:54 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	if (str1 > str2)
	{
		while (len--)
			str1[len] = str2[len];
	}
	else
		ft_memcpy(str1, str2, len);
	return (dst);
}
