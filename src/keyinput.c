#include "../fdf.h"

int		deal_key(int key, mlx_data_t *data)
{
	if (key == 65307 || key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		exit(0);
	}
	return(1);
}