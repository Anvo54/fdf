#include "../fdf.h"

void		draw(int x0, int y0, int x1, int y1, mlx_data_t *data)
{
	line_t	line;

	line.dx = ft_abs(x1 - x0);
	line.sx = x0 < x1 ? 1 : -1;
	line.dy = -ft_abs(y1 - y0);
	line.sy = y0 < y1 ? 1 : -1;
	line.error = line.dx+line.dy;
	line.e2 = 0;
	while (!(x0 == x1 && y0 == y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, x0, y0, 0xffffff);
		line.e2 = 2*line.error;
		if (line.e2 >= line.dy)
		{
			line.error += line.dy;
			x0 += line.sx;
		}
		if (line.e2 <= line.dx)
		{
			line.error += line.dx;
			y0 += line.sy;
		}
	}
}