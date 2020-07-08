#include "../fdf.h"

void zoom(map_t *map)
{
	int i;
	int j;
	int factor;

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

int		deal_key(int key, mlx_data_t *data)
{
	mlx_data_t ploks = *data;
	if (key == 65307 || key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(0);
	}

	if (key == 65451)
	{
		zoom(data->map);
		print_map(data->map, ploks);
	}
	return(1);
}