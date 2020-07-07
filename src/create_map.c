#include "../fdf.h"

map_t		*create_map(int fd)
{
	int maxX;
	int maxY;
	map_t  *kartta;
	coords_t **coords;

	coords = read_coords(fd, &maxX, &maxY);
	kartta = (map_t*)ft_memalloc(sizeof(map_t));
	kartta->coords = coords;
	kartta->height = maxY -1;
	kartta->width = maxX;
	return(kartta);
}