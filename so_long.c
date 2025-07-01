/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:48:31 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/07/01 13:06:17 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	*game;

	game = NULL;
	if (ac != 2)
		ft_free_exit("ERROR\nMissing or wrong parameter\n", game, 1);
	game = malloc(sizeof(t_data));
	if (!game)
		ft_free_exit("ERROR\nGame allocation failure.\n", game, 1);
	game->m_name = av[1];
	game->win = NULL;
	game->collected = 0;
	game->e_count = 0;
	game->p_count = 0;
	game->c_count = 0;
	game->movecounter = 0;
	init_map(game);
	check_members(game);
	set_player_pos(game);
	set_exit(game);
	start_data(game);
	mlx_hook(game->win, 17, 0, close_window_hook, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
}