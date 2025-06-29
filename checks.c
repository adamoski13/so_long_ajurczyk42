/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:25:22 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/06/29 17:19:36 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_members(t_list *master)
{
	char	**map;
	char	*row;

	map = master->map;
	while (*map)
	{
		row = *map;
		while (*row)
		{
			if (*row != '0' && *row != '1' && *row != 'C' && *row != 'E' && *row != 'P')
				ft_free_with_msg("ERROR\nThis map have forbidden letter\n", master);
			if (*row == 'E')
				++master->exit_count;
			else if (*row == 'P')
				++master->player_count;
			else if (*row == 'C')
				++master->points_count;
			row++;
		}
		map++;
	}
	if (master->points_count < 1 || master->player_count != 1 || master->exit_count != 1)
		ft_free_with_msg("ERROR\nSome values are wrong and/or missing\n", master);
}

void	check_walls(t_list *master)
{
	int	i;
	
	i = 0;
	while (master->map[0][i] && master->map[master->map_height - 1][i])
	{
		if (master->map[0][i] != '1' || master->map[master->map_height -1][i] != '1')
			ft_free_with_msg("ERROR\nMap is invalid\n", master);
		i++;
	}
	i = 0;
	while (master->map[i])
	{
		if (master->map[i][0] != '1' || master->map[i][master->map_width -1] != '1')
			ft_free_with_msg("ERROR\nMap is invalid\n", master);
		i++;
	}
}

void	check_for_fit(t_list *master)
{
	int	i;
	
	i = 0;
	if (master->map_width < 5 || master->map_height < 4)
		ft_free_with_msg("ERROR\nInvalid map size\n", master);
	while (i < master->map_height -1)
	{
		if ((int)ft_strlen(master->map[i]) != master->map_width)
			ft_free_with_msg("ERROR\nLines are diffrent\n", master);
		i++;
	}
	// if (master->map_height == master->map_width)
	// 	ft_free_with_msg("ERROR\nMap is not rectangular\n", master);
}

void	check_all(t_list *master)
{
	check_for_fit(master);
	check_walls(master);
	check_members(master);
}

void	check_for_access(t_list *master)
{
	char	*data;

	data = NULL;
	master->fd = open(master->map_name, O_RDONLY);
	if (master->fd < 0)
		ft_free_with_msg("ERROR\nNo such file\n", master);
	if (ft_strcmp((master->map_name + (ft_strlen(master->map_name) - 4)), ".ber"))
		ft_free_with_msg("ERROR\nNo such file extension\n", master);
	data = get_next_line(master->fd);
	if (!data)
		ft_free_with_msg("ERROR\nNothing in this file\n", master);
	free(data);
	close(master->fd);
	master->gathered = 0;
	master->player_count = 0;
	master->points_count = 0;
	master->exit_count = 0;
	master->count_move = 0;
	create_map(master);
}