/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:54:43 by mmartiro          #+#    #+#             */
/*   Updated: 2022/02/25 19:55:03 by mmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ch_initarray(int size)
{
	char	*array;

	array = (char *)malloc(size * sizeof(char));
	if (!array)
		esc("ERROR Malloc\n");
	return (array);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int	len_name(char *string)
{
	int	i;

	i = 0;
	while (string[i] && string[i] != '.')
		i++;
	return (i);
}

int	check_map_name(char *string, char *str)
{
	int		i;
	int		j;
	int		len;
	char	*temp;

	len = ft_strlen(string);
	i = len_name(string);
	j = 0;
	temp = ch_initarray(len - i);
	while (string[i] && i != 0)
		temp[j++] = string[i++];
	temp[j] = '\0';
	len = ft_strlen(str);
	if (!ft_strncmp(temp, str, len))
	{
		if (temp[j] == '\0' && str[4] == '\0')
		{
			free(temp);
			return (0);
		}
	}
	free(temp);
	esc("Error: map's format isn't .ber\n");
	return (0);
}
