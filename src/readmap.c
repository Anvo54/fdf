#include "../fdf.h"

coords_t *convert_to_coords(char **line, int y)
{
	int i;
	int j;
	coords_t *map_line;

	i = 0;
	j = 0;
	while (line[i])
		i++;
	map_line = (coords_t*)malloc(i * sizeof(coords_t));
	while (j < i)
	{
		map_line[j].y = y * 5;
		map_line[j].x = j * 5;
		map_line[j].z = ft_atoi(line[j]);
		free(line[j]);
		j++;
	}
	free(line);
	return(map_line);
}

coords_t		**read_coords(int fd, int *maxX, int *maxY)
{
	coords_t **map;
	char **charmap;
	int y;
	int i;

	y = 0;
	i = 0;
	charmap = (char**)malloc(sizeof(char*) *BUFFER);
	while (get_next_line(fd, &charmap[y]))
		y++;
	*maxY = y;
	*maxX = ft_count_char(charmap[0],' ');
	map = (coords_t**)malloc(y * sizeof(coords_t*));
	while(i < y)
	{
		map[i] = convert_to_coords(ft_strsplit(charmap[i], ' '), i);
		free(charmap[i]);
		i++;
	}
	free(charmap);
	return(map);
}