/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:12:45 by avornane          #+#    #+#             */
/*   Updated: 2019/11/01 11:42:09 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*new;

	i = 0;
	new = (unsigned char*)b;
	while (i < n)
	{
		new[i] = (unsigned char)c;
		i++;
	}
	return (new);
}
