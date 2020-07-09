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
			map->coords[i][j].x *= 1.20;
			map->coords[i][j].y *= 1.20;
			map->coords[i][j].z *= 1.20;
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
			map->coords[i][j].x /= 1.20;
			map->coords[i][j].y /= 1.20;
			map->coords[i][j].z /= 1.20;
			j++;
		}
		i++;
	}
}

void translate(map_t *map, int key)
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
			map->coords[i][j].x += 10;
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

void testf(map_t *kartta){
	int i;
	int j;

	i = 0;
	j = 0;
	int test = (kartta->width / 2);
	int test2 = (kartta->height / 2);
	while (i <= kartta->height)
	{
		j = 0;
		while (j <= kartta->width)
		{
			kartta->coords[i][j].x -= test;
			kartta->coords[i][j].y -= test2;
			j++;
		}
		i++;
	}
	
}


int		deal_key(int key, mlx_data_t *data)
{
	mlx_data_t data_new = *data;

	if (key == 65307 || key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(0);
	}
	if (key == 65451 || key == 65453)
	{
		if (key == 65451)
			zoom(data->map, key);
		if (key == 65453)
			zoomout(data->map);
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		print_map(data->map, data_new);
	}
	if (key == 100)
	{
		translate(data->map, key);
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		print_map(data->map, data_new);
	}

	if (key == 97){
		turniso(data->map);
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		print_map(data->map, data_new);
	}
	if (key == 115)
	{
		testf(data->map);
	}
	return(1);
}