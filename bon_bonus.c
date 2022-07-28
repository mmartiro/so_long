/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bon_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:10:31 by mmartiro          #+#    #+#             */
/*   Updated: 2022/03/15 18:10:36 by mmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bon_bonus.h"

void	bon(t_mlx *mlx)
{
	char	*tmp;

	mlx_string_put(mlx->mlx, mlx->win, 20, 20,
		rgb(255, 255, 255), "count = ");
	tmp = ft_itoa(g_globs.move_count);
	mlx_string_put(mlx->mlx, mlx->win, 100, 20,
		rgb(255, 255, 255), tmp);
	free(tmp);
}

void	esc_n(t_mlx *mlx)
{
	if (mlx->map[(int)mlx->posy][(int)mlx->posx] == 'N')
	{
		ft_sleep();
		esc("");
	}
}
