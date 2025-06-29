/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:21:26 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/06/29 10:59:22 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	endgame(t_list *master, int is_win)
{
	int	i;

	if (master->img)
	{
		i = 0;
		while (i < 5)
		{
			mlx_destroy_image(master->mlx, master->img[i]);
			i++;
		}
		free(master->img);
	}
	if (master->mlx && master->window)
		mlx_destroy_window(master->mlx, master->window);
	if (master->mlx)
	{
		mlx_loop_end(master->mlx);
		mlx_destroy_display(master->mlx);
		free(master->mlx);
	}
	if (is_win == 1)
		score_print(1);
	else if (is_win == 0)
		score_print(0);
	ft_free_with_msg("", master);
}

void	move_left_right(t_list *master, int val)
{
	char	**map;

	map = master->map;
	if (map[master->player_y][master->player_x + val] != '1')
	{
		map[master->player_y][master->player_x] = '0';
		master->player_x += val;
		++master->count_move;
		if (map[master->player_y][master->player_x] == 'C')
			++master->gathered;
		if (map[master->player_y][master->player_x] == 'E'
		&& master->gathered == master->exit_count)
		{
			map[master->player_y][master->player_x] = 'P';
			frame_refresh(master);
			sleep(1);
			endgame(master, 1);
		}
		map[master->player_y][master->player_x] = 'P';
		frame_refresh(master);
	}
}

void	move_up_down(t_list *master, int val)
{
	char	**map;

	map = master->map;
	if (map[master->player_y + val][master->player_x] != '1')
	{
		map[master->player_y][master->player_x] = '0';
		master->player_y += val;
		++master->count_move;
		if (map[master->player_y][master->player_x] == 'C')
			++master->gathered;
		if (map[master->player_y][master->player_x] == 'E'
		&& master->gathered == master->exit_count)
		{
			map[master->player_y + val][master->player_x] = 'P';
			frame_refresh(master);
			sleep(1);
			endgame(master, 1);
		}
		map[master->player_y][master->player_x] = 'P';
		frame_refresh(master);
	}
}