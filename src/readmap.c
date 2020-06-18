/* READMAP */

/* 

Funktio palauttaa map_t arrayn
Funktio saa parametrikseen filedescriptorin ja pointerin map_t arrayhin



 */

#include "../fdf.h"

map_t		**read_map(int fd)
{
	int i;
	int x;
	int y;
	char **charmap;
	char **tmp;
	map_t **result;

	i = 0;
	charmap = (char**)malloc(sizeof(charmap)*BUFFER);
	while (get_next_line(fd, &charmap[i]))
		i++;
	charmap[i] = 0;
	x = ft_count_char(charmap[0], ' ');
	y = i;
	if (!(result = (map_t**)malloc(sizeof(map_t) * y)))
		return(0);
	i = 0;
	while (charmap[i])
	{
		tmp = ft_strsplit(charmap[i]);
		while(tmp[])
	}
	return(i);
}