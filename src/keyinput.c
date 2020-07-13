#include "../fdf.h"

void zoom(map_t *map, int key)
{
	int i;
	int j;
	double f;

	i = 0;
	j = 0;
	while (i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			map->coords[i][j].x *= 2;
			map->coords[i][j].y *= 2;
			map->coords[i][j].z *= 2;
			j++;
		}
		i++;
	}
}

void zoomout(map_t *map)
{
	int i;
	int j;
	double f;

	i = 0;
	j = 0;
	while (i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			map->coords[i][j].x /= 2;
			map->coords[i][j].y /= 2;
			map->coords[i][j].z /= 2;
			j++;
		}
		i++;
	}
}

void translate(map_t *map, int key)
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
	while (i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			if (key == 100 || key == 97)
				map->coords[i][j].x += val;
			if (key == 119 || key == 115)
				map->coords[i][j].y += val;
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
	mlx_data_t data_new = *data;
	ft_putnbr(key);
	if (key == 65307 || key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(0);
	}
	if (key == 65451 || key == 65453 || key == 120 || key == 122)
	{
		if (key == 65451 || key == 120 )
			zoom(data->map, key);
		if (key == 65453 || key == 122)
			zoomout(data->map);
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		print_map(data->map, data_new);
	}
	if (key == 100 || key == 97 || key == 115 || key == 119)
	{
		translate(data->map, key);
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		print_map(data->map, data_new);
	}

	if (key == 113){
		if (data->project != isometric)
		{
			turniso(data->map);
			mlx_clear_window(data->mlx_ptr, data->mlx_win);
			print_map(data->map, data_new);
			data->project = isometric;
		}
	}
	return(1);
}