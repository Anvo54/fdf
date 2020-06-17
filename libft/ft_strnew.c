/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:32:03 by avornane          #+#    #+#             */
/*   Updated: 2019/11/19 13:29:50 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new_str;

	new_str = (char*)malloc(sizeof(*new_str) * (size) + 1);
	if (!new_str)
		return (NULL);
	ft_bzero(new_str, size + 1);
	return (new_str);
}
