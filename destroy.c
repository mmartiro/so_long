/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:06:40 by mmartiro          #+#    #+#             */
/*   Updated: 2022/03/03 18:26:53 by mmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy(int keycode, t_mlx *mlx)
{
	(void)keycode;
	(void)mlx;
	exit(0);
	return (0);
}

void	strdel(char **str)
{
	if (!str || !*str)
		return ;
	free(*str);
	*str = NULL;
}
