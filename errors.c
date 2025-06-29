/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:06:47 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/06/29 11:01:53 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_list *master)
{
	int	i;

	i = -1;
	while (++i < master->map_height)
		free(master->map[i]);
	//free(master->map[i]);
	free(master->map);
	i = -1;
	while (++i <master->map_height)
		free(master->tmap[i]);
	//free(master->tmap[i]);
	free(master->tmap);
	free(master);
}

void	ft_free_with_msg(char *msg, t_list *master)
{
	if (master)
	{
		if (master->map)
			ft_free(master);
		else
			free(master);
	}
	ft_putstr_fd(msg, 1);
	exit(1);
}