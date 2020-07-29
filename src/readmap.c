#include	"../fdf.h"
#include	"../libft/libft.h"

void	get_z_value(coords_t *coord, char *val, mlx_data_t *data)
{
	char **str = ft_strsplit(val, ',');
	coord->z = ft_atoi(str[0]);
	coord->color = (str[1]) ? ft_hextoint(str[1]): -1;
	data->min = (data->min > coord->z) ? coord->z : data->min;
	data->max = (data->max < coord->z) ? coord->z : data->max;
}

coords_t *convert_to_coords(char **line, int y, mlx_data_t *data)
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
		map_line[j].y = y * 10;
		map_line[j].x = (j - ((i - 1) / 2)) * 10;
		get_z_value(&map_line[j], line[j], data);
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