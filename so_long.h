/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:46:51 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/07/01 15:14:44 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define BUFFER_SIZE 1
# define PXL 64
# define COLLECTIBLES "./textures/trinity.xpm"
# define DOOR "./textures/princess.xpm"
# define BG "./textures/floor.xpm"
# define WALL "./textures/wall.xpm"
# define PLAYER "./textures/link.xpm"
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_ESC 65307
# define WIN_CLOSE 17

typedef struct s_data
{
	void	*win;
	void	*mlx;
	void	**img;
	char	**map;
	char	*m_name;
	char	**temp_map;
	int		collected;
	int		e_count;
	int		p_count;
	int		c_count;
	int		movecounter;
	int		m_width;
	int		m_height;
	int		fd;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		scr_x;
	int		scr_y;
}				t_data;

//errors
void	ft_free_exit(char *msg, t_data *game, int code);
void	ft_free(t_data *game);

//utils
void	set_exit(t_data *game);
void	set_player_pos(t_data *game);
void	check_members(t_data *game);
void	init_map(t_data *game);
void	find_height(t_data *game);

//libft_utils
size_t	get_digits(int n);
void	ft_putstr(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_itoa(int n);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t num, size_t n);
char	*ft_strtrim(char *src, char *set);

//game_utils
void	start_data(t_data *game);
void	add_images(t_data *game);
void	print_bg(t_data *game);
void	print_nonmovings(t_data *game);
void	print_player(t_data *game);

//move_utils
int		close_window_hook(t_data *game);
int		key_hook(int key, t_data *game);
void	ft_winloseprint(int is_win);
void	refresh_frame(t_data *game);
void	move_u_d(t_data *game, int val);
void	move_l_r(t_data *game, int val);
void	endgame(t_data *game, int is_win);

//other
char	*get_next_line(int fd);

#endif
