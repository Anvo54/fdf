/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:33:12 by avornane          #+#    #+#             */
/*   Updated: 2020/06/08 16:57:53 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fromat_data(t_mlx_data *data, t_map *kartta)
{
	data->width = 1920;
	data->height = 1080;
	if ((data->mlx_ptr = mlx_init()) == (void *)0)
		exit(0);
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, data->width,
			data->height, "FDF Hive")) == NULL)
		exit(0);
	data->project = isometric;
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	data->img_data = mlx_get_data_addr(data->img_ptr, &(data->bpp),
		&(data->size_line), &(data->endian));
	data->zoom = 1;
	data->translate_x = data->width / 2;
	data->translate_y = data->height / 2;
	data->z_height = 10;
	data->rotate_x = 0;
	data->rotate_y = 0;
	data->rotate_z = 0;
	data->map = kartta;
}

int				main(int argc, char **argv)
{
	t_mlx_data	data;
	t_map		*kartta;
	int			fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		kartta = create_map(fd, &data);
		fromat_data(&data, kartta);
		close(fd);
		mlx_key_hook(data.mlx_win, deal_key, &data);
		print_map(data.map, data);
		mlx_loop(data.mlx_ptr);
	}
	return (0);
}
