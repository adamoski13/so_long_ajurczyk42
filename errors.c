/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:00:02 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/07/01 11:27:17 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_data *game)
{
	int	i;

	i = 0;
	while (i < game->m_height)
	{
		free(game->map[i]);
		i++;
	}
	free (game->map[i]);
	free(game->map);
	i = 0;
	while (i < game->m_height)
	{
		free(game->temp_map[i]);
		i++;
	}
	free(game->temp_map[i]);
	free(game->temp_map);
	free(game);
}

void	ft_free_exit(char *msg, t_data *game, int code)
{
	ft_putstr(msg);
	if (game)
	{
		if (game->map)
			ft_free(game);
		else
			free(game);
	}
	exit(code);
}