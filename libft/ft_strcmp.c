/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 13:37:29 by avornane          #+#    #+#             */
/*   Updated: 2019/10/28 13:52:22 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	if (*(unsigned char *)s1 < *(unsigned char *)s2)
		return (-1);
	if (*(unsigned char *)s1 == *(unsigned char *)s2)
		return (0);
	else
		return (1);
}
