#include "../fdf.h"

void empty_image(mlx_data_t *data)
{
	ft_bzero(data->img_data, data->width * data->height * 4);
}

void zoom(mlx_data_t *data, int key)
{
	if (key == 120)
		data->zoom *= 1.2;
	if (key == 122)
		data->zoom *= 0.8;
}

void	rotate_map(mlx_data_t *data, int key)
{
	if (key == 65362)
		data->rotate_x += 0.05;
	if (key == 65364)
		data->rotate_x -= 0.05;
	if (key == 65361)
		data->rotate_y += 0.05;
	if (key == 65363)
		data->rotate_y -= 0.05;
}

void translate(mlx_data_t *data, int key)
{
	int val;

	if (key == 100 || key == 115)
		val = 10;
	if (key == 97 || key == 119)
		val = -10;
	if (key == 100 || key == 97)
		data->translate_x += val;
	if (key == 119 || key == 115)
		data->translate_y += val;
}

int		deal_key(int key, mlx_data_t *data)
{
	ft_putnbr(key);
	write(1, "\n", 1);
	if (key == 65307 || key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(0);
	}
	if (key == 65451 || key == 65453 || key == 120 || key == 122)
	{
		if (key == 65451 || key == 120 || key == 122)
			zoom(data, key);
		empty_image(data);
		print_map(data->map, *data);
	}
	if (key == 100 || key == 97 || key == 115 || key == 119)
	{
		translate(data, key);
		empty_image(data);
		print_map(data->map, *data);
	}

	if (key == 113){
		if (data->project != isometric)
		{
			data->project = isometric;
			empty_image(data);
			print_map(data->map, *data);
		} else {
			data->project = cartesian;
			empty_image(data);
			print_map(data->map, *data);
		}
	}

	if (key == 114 || key == 101)
	{
		data->z_height += (key == 101) ? -5 : 5;
		empty_image(data);
		print_map(data->map, *data);
	}
	if (key == 65362 || key == 65364 || key == 65361 || key == 65363)
	{
		rotate_map(data, key);
		empty_image(data);
		print_map(data->map, *data);
	}
	return(1);
}