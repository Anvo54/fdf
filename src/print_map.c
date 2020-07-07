#include "../fdf.h"


int print_map(map_t *map, mlx_data_t data)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(i <= map->height)
	{
		j = 0;
		while (j <= map->width)
		{
			if (j != map->width)
				draw(map->coords[i][j].x, map->coords[i][j].y, map->coords[i][j + 1].x, map->coords[i][j].y - map->coords[i][j].z, &data);
			if (i != map->height)
				draw(map->coords[i][j].x, map->coords[i][j].y - map->coords[i][j].z, map->coords[i][j].x, map->coords[i + 1][j].y, &data);
			j++;
		}
		i++;
	}
	return(0);
}