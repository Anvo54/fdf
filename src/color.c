#include "../fdf.h"


double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int			point_color(int minz, int maxz, int curz)
{
	double	percentage;
	percentage = percent(minz, maxz, curz);
	
	if (percentage < 0.2)
		return (0x32a852);
	else if (percentage < 0.4)
		return (0xa86932);
	else if (percentage < 0.7)
		return (0x3261a8);
	else
		return (0xa83232);
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