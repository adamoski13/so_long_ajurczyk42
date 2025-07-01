/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:03:45 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/07/01 13:15:19 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_height(t_data *game)
{
	char	*line;
	int		i;

	i = 0;
	game->m_height = 0;
	game->fd = open(game->m_name, O_RDONLY);
	line = get_next_line(game->fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(game->fd);
	}
	game->m_height = i;
	free(line);
	line = NULL;
	close(game->fd);
}

void	init_map(t_data *game)
{
	char	*line;
	int		i;

	i = 0;
	find_height(game);
	game->map = (char **)malloc((game->m_height + 1) * sizeof(char *));
	game->temp_map = (char **)malloc((game->m_height + 1) * sizeof(char *));
	game->fd = open(game->m_name, O_RDONLY);
	if (!game->map || !game->temp_map)
		ft_free_exit("Error\nMap allocation error!", game, 1);
	line = get_next_line(game->fd);
	while (line)
	{
		game->map[i] = line;
		game->temp_map[i] = ft_strdup(line);
		line = get_next_line(game->fd);
		i++;
	}
	free(line);
	game->map[i] = NULL;
	game->temp_map[i] = NULL;
	game->m_width = (int)ft_strlen(game->map[0]);
	close(game->fd);
}
	
void	check_members(t_data *game)
{
	char	**map;
	char	*row;

	map = game->map;
	while (*map)
	{
		row = *map;
		while (*row)
		{
			if (*row == 'E')
				++game->e_count;
			else if (*row == 'P')
				++game->p_count;
			else if (*row == 'C')
				++game->c_count;
			row++;
		}
		map++;
	}
}

void	set_player_pos(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->p_x = x;
				game->p_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	set_exit(t_data *game)
{
	int		x;
	int		y;
	char	**map;

	map = game->map;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'E')
			{
				game->e_x = x;
				game->e_y = y;
			}
		}
	}
}