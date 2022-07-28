/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:54:43 by mmartiro          #+#    #+#             */
/*   Updated: 2022/02/25 19:55:03 by mmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(t_mlx *mlx, int x, int y)
{
	mlx->map[y][x] = '0';
	mlx->posx = (double)x;
	mlx->posy = (double)y;
}

void	ft_background(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < mlx->screen_h)
	{
		y = 0;
		while (y < mlx->screen_w)
		{
			my_mlx_pixel_put(&mlx->data, y, x, rgb(0, 0, 0));
			y++;
		}
		x++;
	}
}

void	draw_map(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	ft_background(mlx);
	while (y < mlx->map_h)
	{
		x = 0;
		while (x < mlx->map_w)
		{
			if (mlx->map[y][x] == '1')
				draw_texture(mlx, x * 64, y * 64, mlx->wall);
			else if (mlx->map[y][x] == 'C')
				draw_texture(mlx, x * 64, y * 64, mlx->coin);
			else if (mlx->map[y][x] == 'P')
				player_pos(mlx, x, y);
			else if (mlx->map[y][x] == 'N')
				draw_texture(mlx, x * 64, y * 64, mlx->d);
			else if (mlx->map[y][x] == 'E')
				draw_texture(mlx, x * 64, y * 64, mlx->exit);
			++x;
		}
		++y;
	}
}
