/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyinput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:33:12 by avornane          #+#    #+#             */
/*   Updated: 2020/08/03 16:57:53 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	empty_image(t_mlx_data *data)
{
	ft_bzero(data->img_data, data->width * data->height * 4);
}

void	zoom(t_mlx_data *data, int key)
{
	if (key == 120)
		data->zoom *= 1.2;
	if (key == 122)
		data->zoom *= 0.8;
}

void	rotate_map(t_mlx_data *data, int key)
{
	if (key == 65362)
		data->rotate_x -= 0.05;
	if (key == 65364)
		data->rotate_x += 0.05;
	if (key == 44)
		data->rotate_y -= 0.05;
	if (key == 46)
		data->rotate_y += 0.05;
	if (key == 65363)
		data->rotate_z += 0.05;
	if (key == 65361)
		data->rotate_z -= 0.05;
}

void	translate(t_mlx_data *data, int key)
{
	int	val;

	if (key == 100 || key == 115)
		val = 10;
	if (key == 97 || key == 119)
		val = -10;
	if (key == 100 || key == 97)
		data->translate_x += val;
	if (key == 119 || key == 115)
		data->translate_y += val;
}

int		deal_key(int key, t_mlx_data *data)
{
	if (key == 65307 || key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(0);
	}
	if (key == 65451 || key == 65453 || key == 120 || key == 122)
		zoom(data, key);
	if (key == 100 || key == 97 || key == 115 || key == 119)
		translate(data, key);
	if (key == 113)
	{
		if (data->project != isometric)
			data->project = isometric;
		else
			data->project = cartesian;
	}
	if (key == 114 || key == 101)
		data->z_height += (key == 101) ? -1.2 : 1.2;
	if (key == 65362 || key == 65364 || key == 65361 || key == 65363
	|| key == 44 || key == 46)
		rotate_map(data, key);
	empty_image(data);
	print_map(data->map, *data);
	return (1);
}
