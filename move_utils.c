/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamjurczyk <adamjurczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:21:25 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/07/01 19:15:40 by adamjurczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	endgame(t_list *game, int is_win)
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
	if (is_win)
		ft_putstr_fd("*** WINNER ***\n", STDOUT_FILENO);
	else
		ft_putst_fd(":( LOOSER :(\n", STDOUT_FILENO);
	ft_free_exit("", game);
}

void	move_l_r(t_list *game, int val)
{
	char	**map;

	map = game->map;
	if (map[game->player_y][game->player_x + val] != '1')
	{
		map[game->player_y][game->player_x] = '0';
		game->player_x += val;
		++game->movecounter;
		if (map[game->player_y][game->player_x] == 'C')
			++game->collected;
		if (map[game->player_y][game->player_x] == 'E'
		&& game->collected == game->c_count)
		{
			map[game->player_y][game->player_x] = 'P';
			refresh_frame(game);
			sleep(1);
			endgame(game, 1);
		}
		map[game->player_y][game->player_x] = 'P';
		refresh_frame(game);
	}
}

void	move_u_d(t_list *game, int val)
{
	char	**map;

	map = game->map;
	if (map[game->player_y + val][game->player_x] != '1')
	{
		map[game->player_y][game->player_x] = '0';
		game->player_y += val;
		++game->movecounter;
		if (map[game->player_y][game->player_x] == 'C')
			++game->collected;
		if (map[game->player_y][game->player_x] == 'E'
		&& game->collected == game->c_count)
		{
			map[game->player_y + val][game->player_x] = 'P';
			refresh_frame(game);
			sleep(1);
			endgame(game, 1);
		}
		map[game->player_y][game->player_x] = 'P';
		refresh_frame(game);
	}
}

void	refresh_frame(t_list *game)
{
	char	*counter;
	char	*collected;

	print_background(game);
	print_others(game);
	counter = ft_itoa(game->movecounter);
	collected = ft_itoa(game->collected);
	ft_putstr_fd("Count:", STDOUT_FILENO);
	ft_putstr_fd(counter, STDOUT_FILENO);
	ft_putstr_fd("		Collected:", STDOUT_FILENO);
	ft_putstr_fd(collected, STDOUT_FILENO);
	write(1, "\n", 1);
	free(counter);
	free(collected);
}

int	key_hook(int key, t_list *game)
{
	if (key == KEY_UP)
		move_u_d(game, -1);
	else if (key == KEY_DOWN)
		move_u_d(game, 1);
	else if (key == KEY_LEFT)
		move_l_r(game, -1);
	else if (key == KEY_RIGHT)
		move_l_r(game, 1);
	else if (key == KEY_ESC)
		endgame(game, 0);
	else if (key == 12)
		endgame(game, 0);
	return (0);
}

int	close_window_hook(t_list *game)
{
	endgame(game, 0);
	return (0);
}
