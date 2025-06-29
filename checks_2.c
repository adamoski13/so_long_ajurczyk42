/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:07:00 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/06/29 13:02:24 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill_check_for_player(t_list *master, int y, int x)
{
	if (master->tmap[y][x] == '1')
		return ;
	if (master->tmap[y][x] == 'E')
		master->reached_exit = 1;
	if (master->tmap[y][x] == 'C')
		master->gathered++;
	master->tmap[y][x] = '1';
	flood_fill_check_for_player(master, y + 1, x);
	flood_fill_check_for_player(master, y - 1, x);
	flood_fill_check_for_player(master, y, x + 1);
	flood_fill_check_for_player(master, y, x - 1);
}

void	check_path(t_list *master)
{
	char	**map;
	int		row;
	int		col;

	map = master->tmap;
	col = 0;
	while (map[col])
	{
		row = 0;
		while (map[col][row])
		{
			if (map[col][row] != '1')
				ft_free_with_msg("ERROR\nPath isnt reachable\n", master);
			row++;
		}
		col++;
	}
	master->gathered = 0;
	place_exit(master);
}