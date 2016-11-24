/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:50:58 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/24 19:21:38 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

int		main(void)
{
	char		*str = "....\n....\n..##\n..##\n";
	t_tetris	*tetris;
	int			x;
	int			y;
	int			length;

	x = 0;
	y = 0;
	length = 0;
	if (ContainsInvalidChars(str) == FALSE)
	{
		printf("ContainsInvalidChars == FALSE\n");
		if (!(tetris = CreateTetris(str, 'A')))
		{
			printf("CreateTetris throws an Exception\n");
			free(tetris);
			return (0);
		}
	}
	else
		printf("ContainsInvalidChars throws an Exception\n");
	while (length < 16)
	{
		for (int y = 0; y < 4; y++)
		{
			for(int x = 0; x < 4; x++, length++)
				if (tetris->row[x][y] == '#')
					printf("x:[%d] | y:[%d]\n", x, y);
		}
	}
	return (0);
}
