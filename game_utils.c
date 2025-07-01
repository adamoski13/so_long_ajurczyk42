/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:14:47 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/07/01 11:27:10 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_player(t_data *game)
{
	int	x;
	int	y;

	x = game->p_x * 64;
	y = game->p_y * 64;
	mlx_put_image_to_window(game->mlx, game->win, game->img[3], x, y);
}

void	print_nonmovings(t_data *game)
{
	int		x;
	int		y;
	void	*mlx;

	y = -1;
	mlx = game->mlx;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->c_count == game->collected)
			{
				game->map[game->e_y][game->e_x] = 'E';
				mlx_put_image_to_window(mlx, game->win, game->img[1],
					game->e_x * 64, game->e_y * 64);
			}
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(mlx, game->win, game->img[4],
					x * 64, y * 64);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(mlx, game->win, game->img[0],
					x * 64, y * 64);
		}
	}
}

void	print_bg(t_data *game)
{
	int	x;
	int	y;
	int	xx;
	int	yy;

	y = -1;
	yy = 0;
	while (game->map[++y])
	{
		x = -1;
		xx = 0;
		while (game->map[y][++x])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img[2], xx, yy);
			xx += PXL;
		}
		yy += PXL;
	}
}

void	add_images(t_data *game)
{
	int	pxl;

	pxl = PXL;
	game->img = malloc(sizeof(void *) * 9);
	game->img[0] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLES, &pxl, &pxl);
	game->img[1] = mlx_xpm_file_to_image(game->mlx, DOOR, &pxl, &pxl);
	game->img[2] = mlx_xpm_file_to_image(game->mlx, BG, &pxl, &pxl);
	game->img[3] = mlx_xpm_file_to_image(game->mlx, PLAYER, &pxl, &pxl);
	game->img[4] = mlx_xpm_file_to_image(game->mlx, WALL, &pxl, &pxl);
}

void	start_data(t_data *game)
{
	game->mlx = mlx_init();
	add_images(game);
	game->scr_x = (PXL * game->m_width);
	game->scr_y = (PXL * game->m_height);
	game->win = mlx_new_window(game->mlx, game->scr_x, game->scr_y, "so_long");
	print_bg(game);
	print_nonmovings(game);
	print_player(game);
}