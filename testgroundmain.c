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
	int fd;
	char **map;
	char *str;
	fd = open(argv[1], O_RDONLY);
	data.x = 400;
	data.y = 300;
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (-1);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 400, 300, "The window!")) == NULL)
		return (-1);

	/* Lines below for testing */
	map = (char**)malloc(sizeof(char*) * BUFF_SIZE);

	int i = 0;
	while (get_next_line(fd, &str))
	{
		map[i] = ft_strdup(str); 
		i++;
		free(str);
	}

	char **map2d = (char**)malloc(sizeof(char*)* i);
	int y = i;

	/* Check how many X */

	map[i] = 0;
	map2d[i] = 0;
	int j = 0;
	int x = 1;
	int first = 1;
	int checker;
	i = 0;
	while (map[i])
	{
		x = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
			{
				x++;
				while(map[i][j] == ' ')
				j++;
			}
			j++;	
		}
		if (first){
			first = 0;
			checker = x;
		}
		if (checker != x) 
		{
			printf("Broken map!");
			return(0);
		}
		j = 0;
		i++;
	}

	/* Malloc space for the real map */
	map_t *map_data = (map_t*)malloc(y * x * sizeof(map_t));

	i = 0;
	x = -1;
	y = -1;
	int temp;
	while (map[i])
	{
		temp = 0;
		while (map[i][j])
		{
			if (ft_isalnum(map[i][j])){
				x++;
				y++;
				while (ft_isalnum(map[i][j]))
				{
					temp = temp * 10 + map[i][j] - 48;
					j++;
				}
				if (map[i][j] == ' '){
					map_data[i].x = x;
					map_data[i].y = y;
					map_data[i].z = temp;
					temp = 0;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	
	free(map);
	i = 0;	
	close(fd);
	mlx_key_hook(data.mlx_win, deal_key, &data);
	mlx_loop(data.mlx_ptr);

	
	return(0);
}
