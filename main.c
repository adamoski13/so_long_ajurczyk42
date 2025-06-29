/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:01:20 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/06/28 22:52:57 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_list	*master;

	master = NULL;
	if (ac != 2)
		ft_free_with_msg("ERROR\n Missing parameter\n", master);
	master = malloc(sizeof(t_list));
	if (!master)
		ft_free_with_msg("ERROR\nMalloc failure\n", master);
	master->map_name = av[1];
	master->window = NULL;
	check_for_access(master);
	start_game(master);
	mlx_hook(master->window, 17, 0, close_window, master);
	mlx_key_hook(master->window, keys, master);
	mlx_loop(master->mlx);
	return (0);
}

