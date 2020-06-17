/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:08:32 by avornane          #+#    #+#             */
/*   Updated: 2019/11/04 12:20:44 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		start;
	int		total;
	char	*fresh;

	start = 0;
	if (!s)
		return (NULL);
	total = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
	{
		if (s[start + 1] == '\0')
			return (fresh = ft_strnew(0));
		start++;
	}
	while (s[total] == ' ' || s[total] == '\n' || s[total] == '\t')
		total--;
	fresh = ft_strsub(s, start, (total - start) + 1);
	if (fresh == NULL)
		return (NULL);
	return (fresh);
}
