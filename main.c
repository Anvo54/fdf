/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:33:12 by avornane          #+#    #+#             */
/*   Updated: 2020/06/08 16:57:53 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	mlx_data_t *data;
	map_t *kartta;
	int fd;

	if (!(data = (mlx_data_t*)ft_memalloc(sizeof(mlx_data_t))))
		return(-1);
	fd = open(argv[1], O_RDONLY);
	kartta = create_map(fd);
	if ((data->mlx_ptr = mlx_init()) == (void *)0)
		exit(0);
	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, 400, 300, "The window!")) == NULL)
		return (-1);
	data->map = kartta;
	close(fd);
	print_map(data->map, *data);
	mlx_key_hook(data->mlx_win, deal_key, &data);
	mlx_loop(data->mlx_ptr);
	
	return(0);
}
