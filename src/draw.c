/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:33:12 by avornane          #+#    #+#             */
/*   Updated: 2020/08/03 16:57:53 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			add_pixel(t_mlx_data *fdf, int x, int y, int color)
{
	int			i;

	if (x <= fdf->width && x >= 0 && y <= fdf->height && y >= 0)
	{
		i = (x * fdf->bpp / 8) + (y * fdf->size_line);
		fdf->img_data[i] = color;
		fdf->img_data[++i] = color >> 8;
		fdf->img_data[++i] = color >> 16;
	}
}

void			draw(t_coords p1, t_coords p2, t_mlx_data *data)
{
	t_line		line;
	t_coords	p1_o;

	p1_o = p1;
	line.dx = ft_abs(p1.x - p2.x);
	line.sx = p1.x < p2.x ? 1 : -1;
	line.dy = -ft_abs(p1.y - p2.y);
	line.sy = p1.y < p2.y ? 1 : -1;
	line.error = line.dx + line.dy;
	line.e2 = 0;
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		add_pixel(data, p1.x, p1.y, get_color(p1, p1_o, p2, line));
		line.e2 = 2 * line.error;
		if (line.e2 >= line.dy)
		{
			line.error += line.dy;
			p1.x += line.sx;
		}
		if (line.e2 <= line.dx)
		{
			line.error += line.dx;
			p1.y += line.sy;
		}
	}
}
