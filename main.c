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
	mlx_data_t data;
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (-1);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 400, 300, "The window!")) == NULL)
		return (-1);
	/* Lines below for testing */
	int fd;
	char **char_map;
	char **tmp;
	int i = 0;
	int j;
	int x;

	j = 0;
	if(!(char_map = (char**)malloc(sizeof(char*)* BUFFER)))
		return(0);
	map_t **mapv3d;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &char_map[i]))
			i++;
		int j = 0;
		x = ft_count_char(char_map[0], ' ');
		if(!(mapv3d = (map_t**)malloc(sizeof(map_t*) * i)))
			return(0);
		while (j < i)
		{
			tmp = ft_strsplit(char_map[j], ' ');
			if(!(mapv3d[j] = (map_t*)malloc(sizeof(map_t) * x)))
				return(0);
			int k = 0;
			while (tmp[k])
			{
				mapv3d[j][k].x = k * 2;
				mapv3d[j][k].y = j * 2;
				mapv3d[j][k].z = atoi(tmp[k]);
				free(tmp[k]);
				k++;
			}
			if (k != x + 1)
			{
				ft_putstr("Invalid map!");
				return(0);
			}
			free(tmp);
			j++;
		}
		free(char_map);
		print_map(mapv3d, x, i, data);
	}
	mlx_key_hook(data.mlx_win, deal_key, &data);
	mlx_loop(data.mlx_ptr);

	
	return(0);
}
