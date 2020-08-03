/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:33:12 by avornane          #+#    #+#             */
/*   Updated: 2020/08/03 16:57:53 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_map			*create_map(int fd, t_mlx_data *data)
{
	int			max_x;
	int			max_y;
	t_map		*kartta;
	t_coords	**coords;

	kartta = (t_map*)ft_memalloc(sizeof(t_map));
	coords = read_coords(fd, &max_x, &max_y, data);
	kartta->coords = coords;
	kartta->height = max_y - 1;
	kartta->width = max_x;
	return (kartta);
}
