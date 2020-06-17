/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:15:00 by avornane          #+#    #+#             */
/*   Updated: 2019/11/08 17:42:22 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_word_count(char const *s, char c)
{
	int				result;
	int				i;
	int				len;

	len = ft_strlen(s);
	i = 0;
	result = 0;
	while (i < len)
	{
		if (s[i] != c && i < len)
		{
			result++;
			while (s[i] != c && i < len)
				i++;
		}
		i++;
	}
	return (result);
}

static char			*add_word(char const *s, char c, int *j, int len)
{
	size_t			s_size;
	unsigned int	start;
	char			*str;

	s_size = 0;
	start = 0;
	while (*j < len)
	{
		if (s[*j] != c && *j < len)
		{
			start = *j;
			while (s[*j] != c && *j < len)
			{
				s_size++;
				(*j)++;
			}
			str = ft_strsub(s, start, s_size);
			(*j)++;
			if (str != NULL)
				return (str);
		}
		(*j)++;
	}
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**fresh;
	int				words;
	int				i;
	int				j;
	int				len;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	words = get_word_count(s, c);
	if (!(fresh = malloc(sizeof(fresh) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		fresh[i] = add_word(s, c, &j, len);
		i++;
	}
	fresh[i] = NULL;
	return (fresh);
}
