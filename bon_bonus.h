/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bon_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:10:31 by mmartiro          #+#    #+#             */
/*   Updated: 2022/03/15 18:10:36 by mmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BON_BONUS_H
# define BON_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>
# include <mlx.h>

struct s_globs
{
	int	move_count;
	int	is_pressed;
	int	c_count;
}			g_globs;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	data;
	t_data	wall;
	t_data	coin;
	t_data	mario;
	t_data	d;
	t_data	exit;
	double	posx;
	double	posy;
	int		screen_w;
	int		screen_h;
	int		map_w;
	int		map_h;
	char	**map;
}				t_mlx;

void		bon(t_mlx *mlx);
void		esc_n(t_mlx *mlx);
char		*ft_itoa(int n);
int			rgb(int r, int g, int b);
int			esc(char *s);
void		ft_sleep(void);

#endif
