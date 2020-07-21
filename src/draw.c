#include "../fdf.h"

void	add_pixel(mlx_data_t *fdf, int x, int y, int color)
{
	int		i;
	if (x <= fdf->width && y <= fdf->height)
	{
		i = (x * fdf->bpp / 8) + (y * fdf->size_line);
		fdf->img_data[i] = color;
		fdf->img_data[++i] = color >> 8;
		fdf->img_data[++i] = color >> 16;
	}
}
void		draw(int x0, int y0, int x1, int y1, mlx_data_t *data)
{
	line_t	line;

	int color = mlx_get_color_value(data->mlx_ptr, 0xFFFFFF);

	line.dx = ft_abs(x1 - x0);
	line.sx = x0 < x1 ? 1 : -1;
	line.dy = -ft_abs(y1 - y0);
	line.sy = y0 < y1 ? 1 : -1;
	line.error = line.dx+line.dy;
	line.e2 = 0;
	while (!(x0 == x1 && y0 == y1))
	{
		add_pixel(data, x0, y0, color);
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