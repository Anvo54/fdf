#include "../fdf.h"

map_t		*create_map(int fd, mlx_data_t *data)
{
	int maxX;
	int maxY;
	map_t  *kartta;
	coords_t **coords;

	kartta = (map_t*)ft_memalloc(sizeof(map_t));
	coords = read_coords(fd, &maxX, &maxY, data);
	kartta->coords = coords;
	kartta->height = maxY -1;
	kartta->width = maxX;
	return(kartta);
}