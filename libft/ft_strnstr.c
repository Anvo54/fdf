/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:37:42 by avornane          #+#    #+#             */
/*   Updated: 2019/11/05 11:17:48 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		search_needle_len(const char *haystack, const char *needle, \
				int i, size_t len)
{
	int			j;

	j = 0;
	while (haystack[i] != '\0' && haystack[i] == needle[j] && len)
	{
		if (needle[j + 1] == '\0')
			return (1);
		i++;
		j++;
		len--;
	}
	return (0);
}

char			*ft_strnstr(const char *haystack, const char *needle,\
				size_t len)
{
	int			i;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[i] != '\0' && len)
	{
		if (haystack[i] == needle[0])
			if (search_needle_len(haystack, needle, i, len))
			{
				return ((char*)&haystack[i]);
			}
		i++;
		len--;
	}
	return (NULL);
}
