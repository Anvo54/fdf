#include	"../fdf.h"
#include	"../libft/libft.h"

coords_t *convert_to_coords(char **line, int y, mlx_data_t *data)
{
	int i;
	int j;
	coords_t *map_line;

	i = 0;
	j = 0;
	data->min = ft_atoi(line[i]);
	data->max = ft_atoi(line[i]);
	while (line[i])
		i++;
	map_line = (coords_t*)malloc(i * sizeof(coords_t));
	while (j < i)
	{
		map_line[j].y = y * 10;
		map_line[j].x = (j - ((i - 1) / 2)) * 10;
		map_line[j].z = ft_atoi(line[j]);
		data->min = (data->min > map_line[j].z) ? map_line[j].z : data->min;
		data->max = (data->max < map_line[j].z) ? map_line[j].z : data->max;
		map_line[j].color = 0xffffff;
		free(line[j]);
		j++;
	}
	free(line);
	return(map_line);
}

coords_t		**read_coords(int fd, int *maxX, int *maxY, mlx_data_t *data)
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
		map[i] = convert_to_coords(ft_strsplit(charmap[i], ' '), i - ((y - 1) / 2), data);
		free(charmap[i]);
		i++;
	}
	free(charmap);
	return(map);
}