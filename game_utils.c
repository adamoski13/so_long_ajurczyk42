/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamjurczyk <adamjurczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:14:47 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/07/01 19:13:05 by adamjurczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_others(t_list *game)
{
	int		x;
	int		y;
	void	*mlx;

	y = -1;
	mlx = game->mlx;
	while (game->map[y++])
	{
		x = -1;
		while (game->map[y][x++])
		{
			if (game->c_count == game->collected)
			{
				game->map[game->exit_y][game->exit_x] = 'E';
				mlx_put_image_to_window(mlx, game->win, game->img[1], game->exit_x * 64, game->exit_y * 64);
			}
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(mlx, game->win, game->img[4], x * 64, y * 64);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(mlx, game->win, game->img[0], x * 64, y * 64);
		}
	}
	x = game->player_x * 64;
	y = game->player_y * 64;
	mlx_put_image_to_window(game->mlx, game->win, game->img[3], x, y);
}

void	print_background(t_list *game)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	y1 = -1;
	y2 = 0;
	while (game->map[y1++])
	{
		x1 = -1;
		x2 = 0;
		while (game->map[y1][x1++])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img[2], x2, y2);
			x2 = x2 + PXL;
		}
		y2 = y2 + PXL;
	}
}

void	start_game(t_list *game)
{
	int	pxl;

	pxl = PXL;
	game->mlx = mlx_init();
	game->img = malloc(sizeof(void *) * 9);
	game->img[0] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLES, &pxl, &pxl);
	game->img[1] = mlx_xpm_file_to_image(game->mlx, DOOR, &pxl, &pxl);
	game->img[2] = mlx_xpm_file_to_image(game->mlx, BG, &pxl, &pxl);
	game->img[3] = mlx_xpm_file_to_image(game->mlx, PLAYER, &pxl, &pxl);
	game->img[4] = mlx_xpm_file_to_image(game->mlx, WALL, &pxl, &pxl);
	game->scr_x = (game->m_width * PXL);
	game->scr_y = (game->m_height * PXL);
	game->win = mlx_new_window(game->mlx, game->scr_x, game->scr_y, "so_long");
	print_background(game);
	print_others(game);
}
