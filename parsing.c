/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:00:12 by mmartiro          #+#    #+#             */
/*   Updated: 2022/03/07 19:16:00 by mmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	map_width(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

void	func(t_mlx *mlx, char *str, char *line)
{
	mlx->map_h = map_height(str, '\n');
	mlx->map_w = map_width(str, '\n');
	mlx->screen_h = mlx->map_h * 64;
	mlx->screen_w = mlx->map_w * 64;
	mlx->map = ft_split(str, '\n');
	free(str);
	strdel(&line);
}

int	parsing_map(t_mlx *mlx, char *map, int n)
{
	char	*line;
	char	*str;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		esc("Error map\n");
	str = NULL;
	while (1)
	{
		n = get_next_line(fd, &line);
		if (n <= 0)
			break ;
		line = ft_gnl_strjoin(line, "\n");
		str = ft_gnl_strjoin(str, line);
		free(line);
	}
	if (n == 0)
		str = ft_gnl_strjoin(str, line);
	func(mlx, str, line);
	close(fd);
	if (!(check_char(mlx) && check_rec(mlx) && check_borders(mlx)))
		return (0);
	return (1);
}
