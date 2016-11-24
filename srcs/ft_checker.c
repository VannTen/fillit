/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:24:13 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/24 12:40:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

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

static t_point *GetHashLocations(char *str)
{
	char	*tmp;
	int		i;
	int		x;
	int		y;
	t_point	*hash_array;

	tmp = str;
	i = 0;
	x = 0;
	y = 0;
	if (!(hash_array = (t_point *)malloc(sizeof(t_point) * 4)))
		return (NULL);
	while (*tmp)
	{
		if (*tmp == '#')
		{
			hash_array[i].x = x;
			hash_array[i].y = y;
			i++;
		}
		if ((i % 5) == 0 && *tmp == '\n')
		{
			x = 0;
			y++;
		}
		tmp++;
	}
	return (hash_array);
}

static t_bool IsHashAlone(t_point *loc)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		if (ABS(loc[i].x - loc[i+1].x) > 1)
			return (TRUE);
		else if (ABS(loc[i].y - loc[i+1].y) > 1)
			return (TRUE);
		else if (loc[i].x != loc[i+1].x)
			if (loc[i].y != loc[i+1].y)
				return (TRUE);
		else if (loc[i].y != loc[i+1].y)
			if (loc[i].x != loc[i+1].x)
				return (TRUE);
		i++;
	}
	return (FALSE);
}

static t_bool IsValidShape(char *str)
{
	t_point *hash_locations;

	hash_locations = GetHashLocations(str);
	if (!IsHashAlone(hash_locations))
	{
		// Pas de # tout seul
	}
}
