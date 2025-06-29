/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziola <jziola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:47:36 by jziola            #+#    #+#             */
/*   Updated: 2025/06/22 15:19:19 by jziola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	ft_winloseprint(int is_win)
{
	if (is_win == 1)
	{
		ft_putstr("YOU WIN");
		write(1, "\n", 1);
	}
	else
		ft_putstr("YOU LOOSE");
}

int	key_hook(int key, t_data *game)
{
	if (key == KEY_DOWN)
		move_u_d(game, 1);
	else if (key == KEY_UP)
		move_u_d(game, -1);
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

int	close_window_hook(t_data *game)
{
	endgame(game, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*game;

	game = NULL;
	if (argc != 2)
		ft_free_exit("ERROR\nMissing or wrong parameter\n", game, 1);
	game = malloc(sizeof(t_data));
	if (!game)
		ft_free_exit("ERROR\nGame allocation failure.\n", game, 1);
	game->m_name = argv[1];
	game->win = NULL;
	is_valid(game);
	start_data(game);
	mlx_hook(game->win, 17, 0, close_window_hook, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
