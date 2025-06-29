/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:32:01 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/06/29 11:04:10 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player(t_list *master)
{
	int x;
	int y;
	
	x = master->player_x * 64;
	y = master->player_y * 64;
	mlx_put_image_to_window(master->mlx, master->window, master->img[3], x, y);
}

void	points_of_intrests(t_list *master)
{
	int x;
	int y;
	void *mlx;

	y = 0;
	mlx = master->mlx;
	while (master->map[y])
	{
		x = 0;
		while (master->map[y][x])
		{
			if (master->points_count == master->gathered)
			{
				master->map[master->exit_y][master->exit_x] = 'E';
				mlx_put_image_to_window(mlx, master->window, master->img[1], master->exit_x * 64, master->exit_y * 64);
			}
			if (master->map[y][x] == '1')
				mlx_put_image_to_window(mlx, master->window, master->img[4], x * 64, y * 64);
			if (master->map[y][x] == 'C')
				mlx_put_image_to_window(mlx, master->window, master->img[0], x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	background(t_list *master)
{
	int x1;
	int y1;
	int x2;
	int y2;

	y1 = 0;
	y2 = 0;
	while (master->map[y1])
	{
		x1 = 0;
		x2 = 0;
		while (master->map[y1][x1])
		{
			mlx_put_image_to_window(master->mlx, master->window, master->img[2], x2, y2);
			x1++;
			x2 += PXL;
		}
		y1++;
		y2 += PXL;
	}
}

void	illustrations(t_list *master)
{
	int pxl;

	pxl = PXL;
	master->img = malloc(sizeof(void *) * 9);
	master->img[0] = mlx_xpm_file_to_image(master->mlx, COLLECTIBLES, &pxl, &pxl);
	master->img[1] = mlx_xpm_file_to_image(master->mlx, DOOR, &pxl, &pxl);
	master->img[2] = mlx_xpm_file_to_image(master->mlx, BG, &pxl, &pxl);
	master->img[3] = mlx_xpm_file_to_image(master->mlx, PLAYER, &pxl, &pxl);
	master->img[4] = mlx_xpm_file_to_image(master->mlx, WALL, &pxl, &pxl);
}

void	start_game(t_list *master)
{
	master->mlx = mlx_init();
	illustrations(master);
	master->src_x = (PXL * master->map_width);
	master->src_y = (PXL * master->map_height);
	master->window = mlx_new_window(master->mlx, master->src_x, master->src_y, "so_long");
	background(master);
	points_of_intrests(master);
	player(master);
}
