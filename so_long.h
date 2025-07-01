/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamjurczyk <adamjurczyk@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:46:51 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/07/01 19:14:57 by adamjurczyk      ###   ########.fr       */
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

typedef struct s_list
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
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		scr_x;
	int		scr_y;
}				t_list;

//errors
void	ft_free_exit(char *msg, t_list *game);
void	ft_free_mem(t_list *game);

//set_utils
void	set_player_and_exit(t_list *game);
void	init_map(t_list *game);
void	find_height(t_list *game);

//checks
void	check_file(t_data *game);
void	check_map(t_data *game);
void	check_structure(t_list *game);
void	check_path(t_data *game, int y, int x);
void	validate_path(t_data *game);

//libft_utils
size_t	get_digits(int n);
void	ft_putstr_fd(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
//libft_utils_2
size_t	ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_itoa(int n);
char	*ft_substr(char *s, unsigned int start, size_t len);

//game_utils
void	start_game(t_list *game);
void	print_background(t_list *game);
void	print_others(t_list *game);

//move_utils
int		close_window_hook(t_list *game);
int		key_hook(int key, t_list *game);
void	refresh_frame(t_list *game);
void	move_u_d(t_list *game, int val);
void	move_l_r(t_list *game, int val);
void	endgame(t_list *game, int is_win);

//other
char	*get_next_line(int fd);

#endif
