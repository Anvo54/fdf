#include "../fdf.h"

void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void render(coords_t *point, mlx_data_t *data, coords_t cord)
{
	point->x = cord.x;
	point->z = cord.z;
	point->y = cord.y;
	point->x *= data->zoom;
	point->y *= data->zoom;
	point->z *= data->zoom;
	point->x += data->translate_x;
	point->y += data->translate_y;
	point->z += (point->z != 0) ? data->z_height: 0;
	if (data->project == isometric)
		iso(&point->x, &point->y, point->z);
}

int print_map(map_t *map, mlx_data_t data)
{
	int i;
	int j;
	coords_t tmp;
	coords_t tmp1;

	j = 0;
	i = 0;
	while(i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			if (j != map->width)
			{
				render(&tmp, &data, map->coords[i][j]);
				render(&tmp1, &data, map->coords[i][j + 1]);
				draw(tmp, tmp1, &data);
			}
			if (i != map->height)
			{
				render(&tmp, &data, map->coords[i][j]);
				render(&tmp1, &data, map->coords[i + 1][j]);
				draw(tmp, tmp1, &data);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img_ptr, 0, 0);
	return(0);
}