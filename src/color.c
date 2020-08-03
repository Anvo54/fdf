/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:33:12 by avornane          #+#    #+#             */
/*   Updated: 2020/08/03 16:57:53 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

double		percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			point_color(int min_z, int max_z, int cur_z)
{
	double	percentage;

	percentage = percent(min_z, max_z, cur_z);
	if (percentage < 0.2)
		return (0x32a852);
	else if (percentage < 0.4)
		return (0xa86932);
	else if (percentage < 0.7)
		return (0x3261a8);
	else
		return (0xa83232);
}

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			get_color(t_coords cur, t_coords str, t_coords end, t_line delta)
{
	int		red;
	int		green;
	int		blue;
	double	pos;

	if (cur.color == end.color)
		return (cur.color);
	if (delta.dx > delta.dy)
		pos = percent(str.x, end.x, cur.x);
	else
		pos = percent(str.y, end.y, cur.y);
	red = get_light((str.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, pos);
	green = get_light((str.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, pos);
	blue = get_light(str.color & 0xFF, end.color & 0xFF, pos);
	return ((red << 16) | (green << 8) | blue);
}
