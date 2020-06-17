/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:58:32 by avornane          #+#    #+#             */
/*   Updated: 2019/11/21 12:45:05 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int				find_next_line(char **str, char ***l_str)
{
	int			i;
	char		*tmp;

	i = 0;
	if (*str == NULL)
		return (0);
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	**l_str = ft_strsub(*str, 0, i);
	if ((*str)[i] == '\n')
	{
		if ((*str)[i + 1] == '\0')
			ft_strdel(str);
		else
		{
			if (!(tmp = ft_strdup(&(*str)[i + 1])))
				return (-1);
			ft_strdel(str);
			*str = tmp;
		}
	}
	else
		ft_strdel(str);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*str[FD_SIZE];
	char		*tmp;

	if (fd > FD_SIZE || line == NULL || fd < 0 || (read(fd, buf, 0) == -1))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(str[fd], buf);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (find_next_line(&str[fd], &line));
}
