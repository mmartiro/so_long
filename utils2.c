/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:39:47 by mmartiro          #+#    #+#             */
/*   Updated: 2022/03/03 19:59:47 by mmartiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (dstsize == 0)
		return (i);
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	i = 0;
	while (src[i])
		i++;
	return (i);
}

static int	word_count(char const *s, char c)
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

static int	word_length(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	**matrix(char const *s, char c, char **result, int words_count)
{
	int	i;
	int	j;
	int	w_len;

	while (*s == c)
		s++;
	i = -1;
	while (++i < words_count)
	{
		while (*s == c)
			s++;
		j = 0;
		w_len = word_length(s, c);
		result[i] = (char *)malloc(sizeof(char) * (w_len + 1));
		if (!result[i])
			return (NULL);
		while (j < w_len)
		{
			result[i][j++] = *s;
			s++;
		}
		result[i][j] = '\0';
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	int		wcount;

	if (!s)
		return (NULL);
	wcount = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!result)
		return (NULL);
	result = matrix(s, c, result, wcount);
	return (result);
}
