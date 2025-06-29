/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:50:13 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/06/29 19:23:28 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_height(t_list *master)
{
	char	*data;
	int		i;

	i = 0;
	master->map_height = 0;
	master->fd = open(master->map_name, O_RDONLY);
	data = get_next_line(master->fd);
	while (data)
	{
		free(data);
		data = get_next_line(master->fd);
		i++;
	}
	master->map_height = i;
	free(data);
	data = NULL;
	close(master->fd);
}

void	place_exit(t_list *master)
{
	int		x;
	int		y;
	char	**map;

	map = master->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				master->exit_x = x;
				master->exit_y = y;
			}
			x++;
		}
		y++;
	}
}

void	place_player(t_list *master)
{
	int i;
	int j;

	i = 0;
	while (master->map[i])
	{
		j = 0;
		while (master->map[i][j])
		{
			if (master->map[i][j] == 'P')
			{
				master->player_x = j;
				master->player_y = i;
			}
			j++;
		}
		i++;
	}
	flood_fill_check_for_player(master, master->player_y, master->player_x);
	check_path(master);
}

void	create_map(t_list *master)
{
	char	*data;
	int		i;

	i = 0;
	get_height(master);
	master->map = (char **)malloc((master->map_height + 1) * sizeof(char *));
	master->tmap = (char **)malloc((master->map_height + 1) * sizeof(char *));
	master->fd = open(master->map_name, O_RDONLY);
	if (!master->map || !master->tmap)
		ft_free_with_msg("ERROR\nMalloc failure\n", master);
	data = get_next_line(master->fd);
	while (data)
	{
		data = ft_strtrim(data, "\n");
		master->map[i] = data;
		master->tmap[i] = ft_strdup(data);
		data = get_next_line(master->fd);
		i++;
	}
	free(data);
	master->map[i] = NULL;
	master->tmap[i] = NULL;
	master->map_width = (int)ft_strlen(master->map[0]);
	close(master->fd);
	check_all(master);
	place_player(master);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
