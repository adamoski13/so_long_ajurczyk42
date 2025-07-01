

#include "so_long.h"

void	validate_path(t_data *game)
{
	char	**map;
	int		row;
	int		col;

	map = game->temp_map;
	col = 0;
	while (map[col])
	{
		row = 0;
		while (map[col][row])
		{
			if (map[col][row] != '1')
				ft_free_exit("ERROR\nThis map can't be beaten :(\n", game);
			row++;
		}
		col++;
	}
	game->collected = 0;
}

void	check_path(t_data *game, int y, int x)
{
	if (game->temp_map[y][x] == '1')
		return ;
	if (game->temp_map[y][x] == 'E')
		game->reached_exit = 1;
	if (game->temp_map[y][x] == 'C')
		game->collected++;
	game->temp_map[y][x] = '1';
	check_path(game, y + 1, x);
	check_path(game, y - 1, x);
	check_path(game, y, x + 1);
	check_path(game, y, x - 1);
}

void	check_structure(t_list *game)
{
	char	**map;
	char	*row;

	map = game->map;
	while (*map)
	{
		row = *map;
		while (*row)
		{
			if (*row != '0' && *row != '1'
				&& *row != 'C' && *row != 'E' && *row != 'P')
				ft_free_exit("ERROR\nMap structure isn't valid :(\n", game);
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
	if (game->c_count < 1 || game->p_count != 1 || game->e_count != 1)
		ft_free_exit("ERROR\nMap structure isn't valid :(\n", game);
}

void	check_map(t_data *game)
{
	int		i;

	i = -1;
	if (game->m_width < 5 || game->m_height < 4)
		ft_free_exit("ERROR\nSize of this map is too small :(\n", game);
	while (i++ < game->m_height - 1)
	{
		if ((int)ft_strlen(game->map[i]) != game->m_width)
			ft_free_exit("ERROR\nLines on this map aren't equal :(\n", game);
	}
	i = 0;
	while (game->map[0][i] && game->map[game->m_height - 1][i])
	{
		if (game->map[0][i] != '1' || game->map[game->m_height - 1][i] != '1')
			ft_free_exit("ERROR\nMap walls are invalid :(\n", game);
		i++;
	}
	i = -1;
	while (game->map[i++])
	{
		if (game->map[i][0] != '1' || game->map[i][game->m_width - 1] != '1')
			ft_free_exit("ERROR\nMap walls are invalid :(\n", game);
	}
}

void	check_file(t_data *game)
{
	char	*line;

	line = NULL;
	game->fd = open(game->m_name, O_RDONLY);
	if (game->fd < 0)
		ft_free_exit("ERROR\nCan't find this file :(\n", game);
	if (ft_strcmp((game->m_name + (ft_strlen(game->m_name) - 4)), ".ber") != 0)
		ft_free_exit("ERROR\nThis map format isn't valid :(\n", game);
	line = get_next_line(game->fd);
	if (line == NULL)
		ft_free_exit("ERROR\nThere is nothing in this file :(\n", game);
	free(line);
	close(game->fd);
}