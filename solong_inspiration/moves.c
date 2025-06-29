/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziola <jziola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:47:24 by jziola            #+#    #+#             */
/*   Updated: 2025/06/22 15:17:35 by jziola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	endgame(t_data *game, int is_win)
{
	int	i;

	if (game->img)
	{
		i = 0;
		while (i < 5)
		{
			mlx_destroy_image(game->mlx, game->img[i]);
			i++;
		}
		free(game->img);
	}
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_loop_end(game->mlx);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (is_win == 1)
		ft_winloseprint(1);
	else if (is_win == 0)
		ft_winloseprint(0);
	ft_free_exit("", game, 0);
}

void	move_l_r(t_data *game, int val)
{
	char	**map;

	map = game->map;
	if (map[game->p_y][game->p_x + val] != '1')
	{
		map[game->p_y][game->p_x] = '0';
		game->p_x += val;
		++game->movecounter;
		if (map[game->p_y][game->p_x] == 'C')
			++game->collected;
		if (map[game->p_y][game->p_x] == 'E'
		&& game->collected == game->c_count)
		{
			map[game->p_y][game->p_x] = 'P';
			refresh_frame(game);
			sleep(1);
			endgame(game, 1);
		}
		map[game->p_y][game->p_x] = 'P';
		refresh_frame(game);
	}
}

void	move_u_d(t_data *game, int val)
{
	char	**map;

	map = game->map;
	if (map[game->p_y + val][game->p_x] != '1')
	{
		map[game->p_y][game->p_x] = '0';
		game->p_y += val;
		++game->movecounter;
		if (map[game->p_y][game->p_x] == 'C')
			++game->collected;
		if (map[game->p_y][game->p_x] == 'E'
		&& game->collected == game->c_count)
		{
			map[game->p_y + val][game->p_x] = 'P';
			refresh_frame(game);
			sleep(1);
			endgame(game, 1);
		}
		map[game->p_y][game->p_x] = 'P';
		refresh_frame(game);
	}
}

void	refresh_frame(t_data *game)
{
	char	*counter;
	char	*collected;

	print_bg(game);
	print_nonmovings(game);
	print_player(game);
	counter = ft_itoa(game->movecounter);
	collected = ft_itoa(game->collected);
	ft_putstr("Count:");
	ft_putstr(counter);
	ft_putstr("		Collected:");
	ft_putstr(collected);
	write(1, "\n", 1);
	free(counter);
	free(collected);
}
