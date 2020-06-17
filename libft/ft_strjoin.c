/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:09:42 by avornane          #+#    #+#             */
/*   Updated: 2019/11/19 13:27:49 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		total;
	char	*fresh;

	if (!s1 || !s2)
		return (NULL);
	total = (ft_strlen(s1) + ft_strlen(s2));
	fresh = ft_strnew(total);
	if (fresh == NULL)
		return (NULL);
	ft_strcat(fresh, s1);
	ft_strcat(fresh, s2);
	return (fresh);
}
