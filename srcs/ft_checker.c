/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:24:13 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/25 18:10:35 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_checker.h"

const char *patterns_arr[MAX_PATTERNS] = {
	"###...#.........",
	".#...#..##......",
	"#...###.........",
	"##..#...#.......",
	"###.#...........",
	"##...#...#......",
	"..#.###.........",
	"#...#...##......",
	"###..#..........",
	".#..##...#......",
	".#..###.........",
	"#...##..#.......",
	".##.##..........",
	"#...##...#......",
	"##...##.........",
	".#..##..#.......",
	"####............",
	"#...#...#...#...",
	"##..##.........."
};

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
	while (str[++j])
	{
		if (str[j] == '#')
		{
			hash_array[i].x = x;
			hash_array[i].y = y;
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

static char *GetPattern(char *str)
{
	int		i;
	int		j;
	int		hash_count;
	char	*pattern;

	i = 0;
	j = 0;
	hash_count = 0;
	pattern = ft_strnew(16);
	while (str[i] != '#')
		i++;
	while (str[i] && hash_count < 4)
	{
		if (str[i] != '\n')
		{
			pattern[j] = str[i];
			if (str[i] == '#')
				hash_count++;
			j++;
		}
		i++;
	}
	while (j < 16)
		pattern[j++] = '.';
	return (pattern);
}

static t_bool CheckValidPattern(char *pattern)
{
	int		i;

	i = 0;
	while (i < MAX_PATTERNS)
	{
		if (ft_strequ(pattern, patterns_arr[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_tetris *CreateTetris(char *str, char id)
{
	t_point		*hash_locations;
	t_tetris	*tetris;
	char		*pattern;
	int			i;

	if (!(hash_locations = (t_point *)malloc(sizeof(t_point) * 4)))
		return (NULL);
	i = 0;
	if (!(pattern = GetPattern(str)))
	{
		printf("Invalid entry.\n");
		return (NULL);
	}
	if (!(CheckValidPattern(pattern)))
	{
		printf("Invalid pattern.\n");
		return (NULL);
	}
	if (!(hash_locations = GetHashLocations(str, hash_locations, 0)))
		return (NULL);
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
