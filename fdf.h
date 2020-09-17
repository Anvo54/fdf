/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:33:12 by avornane          #+#    #+#             */
/*   Updated: 2020/06/08 16:57:53 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFFER 4096
# define INIT_ZOOM 10
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	enum
{
	isometric,
	cartesian,
	perspective,
}	t_projection;

typedef struct			s_coords
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_coords;

typedef struct			s_map
{
	int					width;
	int					height;
	t_coords			**coords;
}						t_map;

typedef struct			s_mlx_data
{
	void				*mlx_ptr;
	void				*mlx_win;
	void				*img_ptr;
	char				*img_data;
	t_map				*map;
	t_projection		project;
	int					height;
	int					width;
	int					bpp;
	int					size_line;
	int					endian;
	double				zoom;
	double				translate_x;
	double				translate_y;
	double				rotate_x;
	double				rotate_y;
	double				rotate_z;
	double				z_height;
	int					min;
	int					max;
}						t_mlx_data;

typedef struct			s_line
{
	int					dx;
	int					sx;
	int					dy;
	int					sy;
	int					error;
	int					e2;
	int					color;
}						t_line;

int						deal_key(int key, t_mlx_data *data);
void					draw(t_coords p1, t_coords p2, t_mlx_data *data);
int						print_map(t_map *map, t_mlx_data data);
void					read_coords(int fd, t_mlx_data *data, t_map *map);
t_map					*create_map(int fd, t_mlx_data *data);
double					percent(int start, int end, int current);
int						shade(int start, int end, double percentage);
int						point_color(int minz, int maxz, int curz);
int						get_color(t_coords cur, t_coords start,
	t_coords end, t_line del);
void					iso(int *x, int *y, int z);
void					rotate_x(int *y, int *z, t_mlx_data *data);
void					rotate_z(int *x, int *y, t_mlx_data *data);
void					rotate_y(int *x, int *z, t_mlx_data *data);
void					perspect(t_coords *out);
#endif
