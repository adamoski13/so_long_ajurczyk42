/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamjurczyk <adamjurczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:48:31 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/07/01 19:13:08 by adamjurczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_list	*game;

	game = NULL;
	if (ac != 2)
		ft_free_exit("ERROR\nMissing or wrong parameter\n", game);
	game = malloc(sizeof(t_list));
	if (!game)
		ft_free_exit("ERROR\nGame allocation failure.\n", game);
	game->m_name = av[1];
	game->win = NULL;
	game->collected = 0;
	game->e_count = 0;
	game->p_count = 0;
	game->c_count = 0;
	game->movecounter = 0;
	check_file(game);
	init_map(game);
	check_map(game);
	check_structure(game);
	set_player_and_exit(game);
	validate_path(game);
	start_list(game);
	mlx_hook(game->win, 17, 0, close_window_hook, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
}
