/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:50:58 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/25 18:15:25 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

int		main(void)
{
	char		*str = "..3.\n.2..\n....\n..1#\n";
	t_tetris	*tetris;
	int			x;
	int			y;
	int			length;

	x = 0;
	y = 0;
	length = 0;
	printf("Testing the following pattern :\n%s", str);
	if (ContainsInvalidChars(str) == FALSE)
	{
		printf("ContainsInvalidChars == FALSE\n");
		if (!(tetris = CreateTetris(str, 'A')))
		{
			printf("CreateTetris throws an Exception\n");
			free(tetris);
			return (0);
		}
		else
			printf("Pattern is valid !\nSuccesfully created the tetriminos\n");
	}
	else
	{
		printf("ContainsInvalidChars throws an Exception\n");
		return (0);
	}
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
