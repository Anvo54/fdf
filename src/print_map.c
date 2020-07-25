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

void	rotate_x(int x, int *y, int *z, mlx_data_t *data)
{
	int previous_y;
	int previous_z;

	previous_y = *y;
	previous_z = *z;
	*y = previous_y * cos(data->rotate_x) + previous_z * sin(data->rotate_x);
	*z = -previous_y * sin(data->rotate_x) + previous_z * cos(data->rotate_x);
}

void	rotate_y(int *x, int y, int *z, mlx_data_t *data)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(data->rotate_y) + *z * sin(data->rotate_y);
	*z = -previous_x * sin(data->rotate_y) + *z * cos(data->rotate_y);
}

void render(coords_t *point, mlx_data_t *data, coords_t cord)
{
	point->x = cord.x;
	point->z = cord.z;
	point->y = cord.y;
	point->x *= data->zoom;
	point->y *= data->zoom;
	point->z *= data->zoom;
	point->z += (point->z != data->min) ? data->z_height: 0;
	point->color = (point->z <= data->min) ? 0xebdf34: 0xeb4034;
	rotate_x(point->x, &point->y, &point->z, data);
	rotate_y(&point->x, point->y, &point->z, data);
	if (data->project == isometric)
		iso(&point->x, &point->y, point->z);
	point->x += data->translate_x;
	point->y += data->translate_y;
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