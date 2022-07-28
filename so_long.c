/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:55:40 by mmartiro          #+#    #+#             */
/*   Updated: 2022/03/05 19:03:09 by mmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	press(int key, t_mlx *mlx)
{
	g_globs.is_pressed = 1;
	if (key == KEY_W && !is_wall(mlx, (int)mlx->posx, (int)mlx->posy - 1))
	{
		mlx->posy--;
		g_globs.move_count++;
	}
	else if (key == KEY_A && !is_wall(mlx, (int)mlx->posx - 1, (int)mlx->posy))
	{
		mlx->posx--;
		g_globs.move_count++;
	}
	else if (key == KEY_S && !is_wall(mlx, (int)mlx->posx, (int)mlx->posy + 1))
	{
		mlx->posy++;
		g_globs.move_count++;
	}
	else if (key == KEY_D && !is_wall(mlx, (int)mlx->posx + 1, (int)mlx->posy))
	{
		mlx->posx++;
		g_globs.move_count++;
	}
	else if (key == KEY_ESC)
		esc("");
	return (1);
}

void	check_pos(t_mlx *mlx)
{
	int	x;
	int	y;

	x = (int)mlx->posx;
	y = (int)mlx->posy;
	esc_n(mlx);
	if (mlx->map[y][x] == 'C')
	{
		mlx->map[y][x] = '0';
		g_globs.c_count--;
	}
	else if ((mlx->map[y][x] == 'E' && !g_globs.c_count))
	{
		ft_sleep();
		esc("");
	}
}

int	ft_move(t_mlx *mlx)
{
	clear(mlx);
	draw_map(mlx);
	check_pos(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->data.img, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->mario.img,
		mlx->posx * 64, mlx->posy * 64);
	bon(mlx);
	return (1);
}

void	ft_sleep(void)
{
	int	i;

	i = 0;
	while (i < 100000000)
		i++;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		n;

	n = 0;
	if (argc == 2)
	{
		if (!check_map_name(argv[1], ".ber"))
		{
			mlx.mlx = mlx_init();
			parsing_map(&mlx, argv[1], n);
			mlx.win = mlx_new_window(mlx.mlx, mlx.screen_w,
					mlx.screen_h, "./so_long");
			set_img(&mlx);
			set_addr(&mlx);
			mlx_loop_hook(mlx.mlx, ft_move, &mlx);
			mlx_hook(mlx.win, 17, 1L << 17, ft_destroy, &mlx);
			mlx_hook(mlx.win, 2, 1L << 0, press, &mlx);
			mlx_hook(mlx.win, 3, 1L << 0, release, &mlx);
			mlx_loop(mlx.mlx);
		}
	}
	else
		esc("Argument error\n");
	return (0);
}
