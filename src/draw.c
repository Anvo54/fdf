#include "../fdf.h"

double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(coords_t current, coords_t start, coords_t end, line_t delta)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (current.color == end.color)
        return (current.color);
    if (delta.dx > delta.dy)
        percentage = percent(start.x, end.x, current.x);
    else
        percentage = percent(start.y, end.y, current.y);
    red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

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