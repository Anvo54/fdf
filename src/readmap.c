/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:33:12 by avornane          #+#    #+#             */
/*   Updated: 2020/08/03 16:57:53 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "../libft/libft.h"

void			get_z_value(t_coords *coord, char *val, t_mlx_data *data)
{
	char		**str;
	int 		i;

	i = 0;
	str = ft_strsplit(val, ',');
	coord->z = ft_atoi(str[0]);
	coord->color = (str[1]) ? ft_hextoint(str[1]) : -1;
	data->min = (data->min > coord->z) ? coord->z : data->min;
	data->max = (data->max < coord->z) ? coord->z : data->max;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_coords		*convert(char **line, int y, t_mlx_data *data)
{
	int			i;
	int			j;
	t_coords	*map_line;

	i = 0;
	j = 0;
	while (line[i])
		i++;
	map_line = (t_coords*)malloc(i * sizeof(t_coords));
	while (j < i)
	{
		map_line[j].y = y * 10;
		map_line[j].x = (j - ((i - 1) / 2)) * 10;
		get_z_value(&map_line[j], line[j], data);
		free(line[j]);
		j++;
	}
	free(line);
	return (map_line);
}

t_coords		**read_coords(int fd, int *max_x, int *max_y, t_mlx_data *data)
{
	t_coords	**map;
	char		**charmap;
	char		*count;
	int			y;
	int			i;

	y = 0;
	i = 0;
	charmap = (char**)malloc(sizeof(char*) * BUFFER);
	while (get_next_line(fd, &charmap[y]))
		y++;
	*max_y = y;
	count = ft_strtrim(charmap[0]);
	*max_x = ft_count_char(count, ' ');
	free(count);
	map = (t_coords**)malloc(y * sizeof(t_coords*));
	while (i < y)
	{
		map[i] = convert(ft_strsplit(charmap[i], ' '), i - ((y - 1) / 2), data);
		free(charmap[i]);
		i++;
	}
	free(charmap);
	return (map);
}
