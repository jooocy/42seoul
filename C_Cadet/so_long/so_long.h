/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoo <jojoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:19:37 by jojoo             #+#    #+#             */
/*   Updated: 2022/10/26 02:32:12 by jojoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 			42
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include "libft/libft.h"

typedef struct s_map{
	int		height;
	int		width;
	char	**map;
}	t_map;

typedef struct s_image
{
	void	*wall;
	void	*exit;
	void	*ground;
	void	*player;
	void	*collector;
	int		size;
}	t_image;

typedef struct s_game
{
	int	movement;
	int	collector;
	int	player_i;
	int	player_j;
}	t_game;


typedef struct s_var{
	void		*mlx;
	void		*window;
	t_game		games;
	t_map		maps;
	t_image		images;
}	t_var;

typedef struct s_list
{
	char			*content;
	int				fd;
	struct s_list	*next;
}	t_list;

int		my_strlen(char *s1, char token);
char	*my_strjoin(char *s1, char *s2, int num);
char	*ft_split_join(char *s1, char *s2, t_list *lst_str);
int		my_strchr(const char *str, int to_find);
char	*load_backup(t_list **lst_buff, int fd);
char	*save_buff(t_list **lst_buff, char *str_buff, char *content);
char	*read_file(t_list **lst_buff, int fd, char *read_buff, char *road_data);
char	*ft_resave(t_list **lst_buff, char *str);
char	*get_next_line(int fd);
void	check_file_name(char *file);
int		find(char *str, char *to_find);
void	check_maps(t_var *vars);
void	check_rectangular(t_var *vars);
void	check_walls(t_var *vars);
void	check_elements(t_var *vars);
void	init_vars(t_var *vars);
void	set_images(t_var *vars);
int		count_collector(t_var *vars);
void	get_maps(char *file, t_var *vars);
void	printf_map(t_var *vars);
void	render(t_var *vars);
void	set(t_var *vars, int i, int j);
int		key_press(int keycode, t_var *vars);
void	handle_movement(t_var *vars, int next_i, int next_j);
int		close_game(t_var *vars);

#endif