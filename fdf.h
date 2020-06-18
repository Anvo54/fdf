#ifndef FDF_H
# define FDF_H
# define BUFFER 4096

typedef struct			mlx_data_s
{
	void				*mlx_ptr;
	void				*mlx_win;
}						mlx_data_t;

typedef struct			line_s
{
	int					dx;
	int					sx;
	int					dy;
	int					sy;
	int					error;
	int					e2;
}						line_t;

typedef struct			map_s
{
	int					x;
	int					y;
	int					z;
	int 				maxX;
	int					maxY;
	int					color;
}						map_t;


#include	"mlx.h"
#include	<stdlib.h>
#include	<math.h>
#include	"libft/libft.h"
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>  
// For debug //
#include <stdio.h>

int			deal_key(int key, mlx_data_t *data);
void		draw(int x0, int y0, int x1, int y1, mlx_data_t *data);
int			print_map(map_t **map, int maxX ,int maxY, mlx_data_t data);
int			read_map(int fd, map_t **map);
#endif