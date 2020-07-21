#include "../fdf.h"

void empty_image(mlx_data_t *data)
{
	ft_bzero(data->img_data, data->width * data->height * 4);
}

void zoom(mlx_data_t *data, int key)
{
	if (key == 120)
		data->zoom *= 1.2;
	if (key == 122)
		data->zoom *= 0.8;
}

void zoomout(map_t *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			map->coords[i][j].x /= 1.2;
			map->coords[i][j].y /= 1.2;
			map->coords[i][j].z /= 1.2;
			j++;
		}
		i++;
	}
}

void translate(mlx_data_t *data, int key)
{
	int i;
	int j;
	int val;

	i = 0;
	j = 0;
	if (key == 100 || key == 115)
		val = 10;
	if (key == 97 || key == 119)
		val = -10;
	while (i <= data->map->height)
	{
		j = 0;
		while (j <= data->map->width)
		{
			if (key == 100 || key == 97)
				data->map->coords[i][j].x += val;
			if (key == 119 || key == 115)
				data->map->coords[i][j].y += val;
			j++;
		}
		i++;
	}
}

void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}


void turniso(map_t *map)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			iso(&map->coords[i][j].x, &map->coords[i][j].y, map->coords[i][j].z);
			j++;
		}
		i++;
	}
}

int		deal_key(int key, mlx_data_t *data)
{
	ft_putnbr(key);
	if (key == 65307 || key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(0);
	}
	if (key == 65451 || key == 65453 || key == 120 || key == 122)
	{
		if (key == 65451 || key == 120 || key == 122)
			zoom(data, key);
		empty_image(data);
		print_map(data->map, *data);
	}
	if (key == 100 || key == 97 || key == 115 || key == 119)
	{
		translate(data, key);
		empty_image(data);
		print_map(data->map, *data);
	}

	if (key == 113){
		if (data->project != isometric)
		{
			turniso(data->map);
			empty_image(data);
			print_map(data->map, *data);
			data->project = isometric;
		}
	}
	return(1);
}