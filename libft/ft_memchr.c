/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:24:12 by avornane          #+#    #+#             */
/*   Updated: 2019/10/25 13:31:25 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*value;
	unsigned char	*ptr;

	ptr = (unsigned char*)s;
	value = NULL;
	while (n)
	{
		if (*ptr == (unsigned char)c)
		{
			value = ptr;
			return (value);
		}
		ptr++;
		n--;
	}
	return (value);
}
