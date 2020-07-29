#include "../fdf.h"



void	add_pixel(mlx_data_t *fdf, int x, int y, int color)
{
	int		i;
	if (x < fdf->width && y < fdf->height)
	{
		i = (x * fdf->bpp / 8) + (y * fdf->size_line);
		fdf->img_data[i] = color;
		fdf->img_data[++i] = color >> 8;
		fdf->img_data[++i] = color >> 16;
	}
}
void		draw(coords_t p1, coords_t p2, mlx_data_t *data)
{
	line_t	line;
	coords_t p1_o = p1;

	line.dx = ft_abs(p1.x - p2.x);
	line.sx = p1.x < p2.x ? 1 : -1;
	line.dy = -ft_abs(p1.y - p2.y);
	line.sy = p1.y < p2.y ? 1 : -1;
	line.error = line.dx+line.dy;
	line.e2 = 0;
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		add_pixel(data, p1.x, p1.y, get_color(p1, p1_o, p2, line));
		line.e2 = 2*line.error;
		if (line.e2 >= line.dy)
		{
			line.error += line.dy;
			p1.x += line.sx;
		}
		if (line.e2 <= line.dx)
		{
			line.error += line.dx;
			p1.y += line.sy;
		}
	}
}