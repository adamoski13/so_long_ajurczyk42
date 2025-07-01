/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamjurczyk <adamjurczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:00:02 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/07/01 19:13:04 by adamjurczyk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_mem(t_list *game)
{
	int	i;

	i = -1;
	while (i++ < game->m_height)
		free(game->map[i]);
	free (game->map[i]);
	free(game->map);
	i = -1;
	while (i++ < game->m_height)
		free(game->temp_map[i]);
	free(game->temp_map[i]);
	free(game->temp_map);
	free(game);
}

void	ft_free_exit(char *msg, t_list *game)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	if (game)
	{
		if (game->map)
			ft_free_mem(game);
		else
			free(game);
	}
	exit(1);
}
