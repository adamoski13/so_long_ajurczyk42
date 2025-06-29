/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziola <jziola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:47:42 by jziola            #+#    #+#             */
/*   Updated: 2025/06/22 15:26:04 by jziola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

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

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		**img;
	char		**map;
	char		**temp_map;
	char		*m_name;
	int			fd;
	int			reached_exit;
	int			e_x;
	int			e_y;
	int			p_x;
	int			p_y;
	int			prev_x;
	int			prev_y;
	int			collected;
	int			e_count;
	int			p_count;
	int			c_count;
	int			movecounter;
	int			scr_x;
	int			scr_y;
	int			m_width;
	int			m_height;	
}				t_data;

//utils.c
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);

//utils2.c
void	ft_free(t_data *game);
void	ft_free_exit(char *msg, t_data *game, int code);
void	ft_putstr(char *str);
char	*ft_itoa(int n);

//so_long.c
void	ft_winloseprint(int is_win);

//gnl
char	*get_next_line(int fd);

//map_check1.c
void	check_walls(t_data *game);
void	find_height(t_data *game);
void	is_rectangular(t_data *game);
void	init_map(t_data *game);
void	is_valid(t_data *game);

//map_check2.c
void	validate_path(t_data *game);
void	check_path(t_data *game, int y, int x);
void	set_player_pos(t_data *game);
void	check_members(t_data *game);
void	set_exit(t_data *game);

//graphics.c
void	print_bg(t_data *game);
void	start_data(t_data *game);
void	add_images(t_data *game);
void	print_nonmovings(t_data *game);
void	print_player(t_data *game);

//moves.c
void	refresh_frame(t_data *game);
void	move_l_r(t_data *game, int val);
void	move_u_d(t_data *game, int val);
void	endgame(t_data *game, int is_win);

#endif
