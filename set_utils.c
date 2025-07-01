/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamjurczyk <adamjurczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:03:45 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/07/01 19:13:07 by adamjurczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_height(t_list *game)
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

void	init_map(t_list *game)
{
	char	*line;
	int		i;

	i = 0;
	find_height(game);
	game->map = (char **)malloc((game->m_height + 1) * sizeof(char *));
	game->temp_map = (char **)malloc((game->m_height + 1) * sizeof(char *));
	game->fd = open(game->m_name, O_RDONLY);
	if (!game->map || !game->temp_map)
		ft_free_exit("Error\nMap allocation error!", game);
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

void	set_player_and_exit(t_list *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[y++])
	{
		x = -1;
		while (game->map[y][x++])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
			}
		}
	}
	check_path(game, game->player_y, game->player_x);
}
