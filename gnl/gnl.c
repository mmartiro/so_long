/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:28:39 by mmartiro          #+#    #+#             */
/*   Updated: 2022/03/13 18:29:09 by mmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	read_result(int r, char **line, char **tmp)
{
	if (r < 0)
		return (-1);
	*line = get_before_str(*tmp);
	*tmp = del(*tmp);
	if (r == 0 && !*tmp)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int				r;
	char			*buffer;
	static char		*tmp;
	int				buffer_size;

	buffer_size = 1;
	if (fd < 0 || !line || buffer_size <= 0)
		return (-1);
	buffer = malloc(buffer_size + 1);
	if (!(buffer))
		return (-1);
	while (1)
	{
		r = read(fd, buffer, buffer_size);
		if (r <= 0)
			break ;
		buffer[r] = '\0';
		tmp = ft_gnl_strjoin(tmp, buffer);
		if (get_char(tmp, '\n') || get_char(tmp, '\0'))
			break ;
	}
	free(buffer);
	return (read_result(r, line, &tmp));
}
