#include "../fdf.h"

void render(point_t *point, mlx_data_t *data)
{
	point->x *= data->zoom;
	point->y *= data->zoom;
	point->z *= data->zoom;
}

int print_map(map_t *map, mlx_data_t data)
{
	int i;
	int j;
	point_t tmp;
	point_t tmp1;

	j = 0;
	i = 0;
	while(i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			if (j != map->width)
			{
				tmp.x = map->coords[i][j].x;
				tmp.y = map->coords[i][j].y;
				tmp.z = map->coords[i][j].z;
				tmp1.x = map->coords[i][j + 1].x;
				tmp1.y = map->coords[i][j + 1].y;
				tmp1.z = map->coords[i][j + 1].z;
				render(&tmp, &data);
				render(&tmp1, &data);
				draw(tmp.x, tmp.y, tmp1.x, tmp1.y, &data);
			}
			//	draw(map->coords[i][j].x, map->coords[i][j].y, map->coords[i][j + 1].x, map->coords[i][j + 1].y, &data);
			if (i != map->height)
			{
				tmp.x = map->coords[i][j].x;
				tmp.y = map->coords[i][j].y;
				tmp.z = map->coords[i][j].z;
				tmp1.x = map->coords[i + 1][j].x;
				tmp1.y = map->coords[i + 1][j].y;
				tmp1.z = map->coords[i + 1][j].z;
				render(&tmp, &data);
				render(&tmp1, &data);
				draw(tmp.x, tmp.y, tmp1.x, tmp1.y, &data);
			}
			//	draw(map->coords[i][j].x, map->coords[i][j].y, map->coords[i + 1][j].x, map->coords[i + 1][j].y, &data);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img_ptr, 0, 0);
	return(0);
}