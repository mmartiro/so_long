/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:39:30 by mmartiro          #+#    #+#             */
/*   Updated: 2022/03/13 17:39:39 by mmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_globs(void)
{
	g_globs.c_count = 0;
	g_globs.is_pressed = 0;
	g_globs.move_count = 0;
}

int	esc(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	exit(0);
}

int	check_char(t_mlx *mlx)
{
	int	arr[5];

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = -1;
	while (++arr[3] < mlx->map_h)
	{
		arr[4] = -1;
		while (++arr[4] < mlx->map_w)
		{
			if (mlx->map[arr[3]][arr[4]] == 'C')
				arr[0]++;
			else if (mlx->map[arr[3]][arr[4]] == 'P')
				arr[1]++;
			else if (mlx->map[arr[3]][arr[4]] == 'E')
				arr[2]++;
			else if (mlx->map[arr[3]][arr[4]] != '0'
				&& mlx->map[arr[3]][arr[4]] != '1'
				&& mlx->map[arr[3]][arr[4]] != 'N')
				esc("Error: Map have invalid character\n");
		}
	}
	g_globs.c_count = arr[0];
	if (arr[1] > 1 || arr[2] > 1)
		esc("Error: Map must have 1 C & 1 P\n");
	if (!(arr[0] && arr[1] && arr[2]))
		esc("Error: Not all the needed characters were found!\n");
	return (1);
}

int	check_rec(t_mlx *mlx)
{
	int	i;

	i = 1;
	while (i < mlx->map_h)
	{
		if (mlx->map_w != (int)ft_strlen(mlx->map[i]))
			esc("Error: The map is not rectangular!\n");
		i++;
	}
	return (1);
}

int	check_borders(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->map_h)
	{
		j = 0;
		while (j < mlx->map_w)
		{
			if (i == 0 || i == mlx->map_h - 1 || j == mlx->map_w - 1 || j == 0)
				if (mlx->map[i][j] != '1')
					esc("Error: The map must have solid borders!\n");
			j++;
		}
		i++;
	}
	return (1);
}
