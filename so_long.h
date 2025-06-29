/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 12:01:22 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/06/29 11:51:16 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"

# define BUFFER_SIZE 1
# define PXL 64
# define COLLECTIBLES "./textures/coral.xpm"
# define DOOR "./textures/bin.xpm"
# define BG "./textures/water.xpm"
# define WALL "./textures/palm.xpm"
# define PLAYER "./textures/pigeon.xpm"
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_ESC 65307
# define WIN_CLOSE 17

typedef struct s_list
{
	void		*mlx;
	void		*window;
	void		**img;
	char		**map;
	char		**tmap;
	char		*map_name;
	int			fd;
	int			reached_exit;
	int			exit_x;
	int			exit_y;
	int			player_x;
	int			player_y;
	int			prev_x;
	int			prev_y;
	int			gathered;
	int			player_count;
	int			points_count;
	int			exit_count;
	int			count_move;
	int			src_x;
	int			src_y;
	int			map_width;
	int			map_height;
}	t_list;

//errors
void	ft_free(t_list *master);
void	ft_free_with_msg(char *msg, t_list *master);

//checks
void	check_for_access(t_list *master);
void	check_all(t_list *master);
void	check_for_fit(t_list *master);
void	check_walls(t_list *master);
void	check_members(t_list *master);
void	check_path(t_list *master);
void	flood_fill_check_for_player(t_list *master, int y, int x);

//utils
void	create_map(t_list *master);
void	place_player(t_list *master);
void	place_exit(t_list *master);
void	get_height(t_list *master);
void	start_game(t_list *master);
void	illustrations(t_list *master);
void	background(t_list *master);
void	points_of_intrests(t_list *master);
void	player(t_list *master);
void	frame_refresh(t_list *master);
int		close_window(t_list *master);
int		keys(int key, t_list *master);
void	score_print(int is_win);
void	move_up_down(t_list *master, int val);
void	move_left_right(t_list *master, int val);
void	endgame(t_list *master, int is_win);
int		ft_strcmp(char *s1, char *s2);

//gnl
char	*read_buffer_size_line(int fd, char *buffer_line, char *source);
char	*cut_buffer_line(char *line);
char	*cut_line(char *line);
char	*get_next_line(int fd);

#endif