/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:24:13 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/24 19:21:37 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/ft_checker.h"

t_bool ContainsInvalidChars(char *str)
{
	char	*tmp;
	size_t	p_count;
	size_t	h_count;
	size_t	endl_count;

	tmp = str;
	p_count = 0;
	h_count = 0;
	endl_count = 0;
	while (*tmp)
	{
		if (*tmp == '.')
			p_count++;
		else if (*tmp == '#')
			h_count++;
		else if (*tmp == '\n')
			endl_count++;
		else
			return (TRUE);
		tmp++;
	}
	if (p_count != 12 || h_count != 4 || endl_count != 4)
		return (TRUE);
	return (FALSE);
}

static t_point *GetHashLocations(char *str, t_point *hash_array, int i)
{
	int		j;
	int		x;
	int		y;

	j = -1;
	x = 0;
	y = 0;
	printf("%s", str);
	while (str[++j])
	{
		if (str[j] == '#')
		{
			hash_array[i].x = x;
			hash_array[i].y = y;
			printf("Attributing values to hash_array[%d] [%d][%d]\n", i, hash_array[i].x, hash_array[i].y);
			i++;
		}
		x++;
		if (j == 4 || j == 9 || j == 14 || j == 19)
		{
			if (str[j] != '\n')
				return (NULL);
			x = 0;
			y++;
		}
	}
	return (hash_array);
}

static t_bool IsHashAlone(t_point *loc)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		printf("Comparing loc[%lu].[%d][%d] with loc[%lu].[%d][%d]\n", i, loc[i].x,loc[i].y, i +1, loc[i+1].x, loc[i+1].y);
		if (ABS(loc[i].x - loc[i+1].x) > 1)
			return (TRUE);
		else if (ABS(loc[i].y - loc[i+1].y) > 1)
			return (TRUE);
		else if (loc[i].x != loc[i+1].x)
		{
			if (loc[i].y != loc[i+1].y)
				return (TRUE);
		}
		else if (loc[i].y != loc[i+1].y)
		{
			if (loc[i].x != loc[i+1].x)
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_tetris *CreateTetris(char *str, char id)
{
	t_point		*hash_locations;
	t_tetris	*tetris;
	int			i;

	if (!(hash_locations = (t_point *)malloc(sizeof(t_point) * 4)))
		return (NULL);
	i = 0;
	if (!(hash_locations = GetHashLocations(str, hash_locations, i)))
		return (NULL);
	if (IsHashAlone(hash_locations) == TRUE)
	{
		printf("Invalid tetriminos.\n");
		return (NULL);
	}
	if (!(tetris = (t_tetris *)malloc(sizeof(*tetris))))
		return (NULL);
	tetris->id = id;
	while (i < 4)
	{
		printf("Adding to tetris->row[%d] [%d][%d]\n", i, hash_locations[i].x, hash_locations[i].y);
		tetris->row[hash_locations[i].x][hash_locations[i].y] = '#';
		i++;
	}
	return (tetris);
}
