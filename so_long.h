/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:55:40 by mmartiro          #+#    #+#             */
/*   Updated: 2022/03/05 19:03:09 by mmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <mlx.h>
# include "gnl/gnl.h"
# include "bon_bonus.h"
# define VALID_MAP_CHARACTERS " 01ECP"

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_ESC		53

int			ft_destroy(int keycode, t_mlx *mlx);
int			is_wall(t_mlx *mlx, int x, int y);
int			release(int key);
void		clear(t_mlx *mlx);
int			check_borders(t_mlx *mlx);
int			check_rec(t_mlx *mlx);
int			check_char(t_mlx *mlx);
void		init_globs(void);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			get_color(t_data *data, int x, int y);
void		draw_walls(t_mlx *mlx, int x, int y);
void		draw_texture(t_mlx *mlx, int x, int y, t_data texture);
int			parsing_map(t_mlx *mlx, char *map, int n);
void		set_img(t_mlx *mlx);
void		set_addr(t_mlx *mlx);
int			check_char(t_mlx *mlx);
int			check_rec(t_mlx *mlx);
int			check_borders(t_mlx *mlx);
char		*ft_strcat(char *dest, char *src);
char		*ft_strdup(char *s1);
char		**ft_split(char *s, char c);
int			ft_strlen(char *str);
int			name_check(char *str);
int			ft_in_set(char c, char const *set);
char		*ft_strjoin(char *s1, char *s2);
void		clear(t_mlx *mlx);
int			release(int key);
int			press(int key, t_mlx *mlx);
int			ft_move(t_mlx *mlx);
void		draw_map(t_mlx *mlx);
void		*ft_calloc(size_t count, size_t size);	
void		strdel(char **str);
int			check_map_name(char *string, char *str);

#endif
