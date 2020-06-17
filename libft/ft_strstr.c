/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:46:38 by avornane          #+#    #+#             */
/*   Updated: 2019/11/05 11:14:41 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		search_needle(const char *haystack, const char *needle, int i)
{
	int			j;

	j = 0;
	while (haystack[i] != '\0' && haystack[i] == needle[j])
	{
		if (needle[j + 1] == '\0')
			return (1);
		i++;
		j++;
	}
	return (0);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	int			i;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
			if (search_needle(haystack, needle, i))
			{
				return ((char*)&haystack[i]);
			}
		i++;
	}
	return (NULL);
}
