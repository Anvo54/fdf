/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 11:33:38 by avornane          #+#    #+#             */
/*   Updated: 2019/10/31 12:08:36 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*fresh;
	unsigned int	str_len;
	int				i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	fresh = ft_strnew(len);
	if (fresh == NULL)
		return (NULL);
	if (start > str_len)
		return (NULL);
	while (len && s[start] != '\0')
	{
		fresh[i] = s[start];
		i++;
		len--;
		start++;
	}
	fresh[i] = '\0';
	return (fresh);
}
