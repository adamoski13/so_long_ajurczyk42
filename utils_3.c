/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:02:26 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/06/28 22:34:52 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	score_print(int is_win)
{
	if (is_win == 1)
	{
		ft_putstr_fd("WINNER\n", 1);
	}
	else
		ft_putstr_fd("LOSSER\n", 1);
}

int	keys(int key, t_list *master)
{
	if (key == KEY_UP)
		move_up_down(master, -1);
	else if (key == KEY_DOWN)
		move_up_down(master, 1);
	else if (key == KEY_LEFT)
		move_left_right(master, -1);
	else if (key == KEY_RIGHT)
		move_left_right(master, 1);
	else if (key == KEY_ESC)
		endgame(master, 0);
	else if (key == 12)
		endgame(master, 0);
	return (0);
}

int	close_window(t_list *master)
{
	endgame(master, 0);
	return (0);
}

void	frame_refresh(t_list *master)
{
	char	*counter;
	char	*score;

	background(master);
	points_of_intrests(master);
	player(master);
	counter = ft_itoa(master->count_move);
	score = ft_itoa(master->gathered);
	printf("Count: %s       Collected: %s\n", counter, score);
	free(counter);
	free(score);
}