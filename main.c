/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:50:58 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/24 18:26:47 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

int		main(void)
{
	char		*str = "####\n....\n....\n....\n";
	t_tetris	*tetris;
	int			x;
	int			y;
	int			length;

	length = 0;
	if (ContainsInvalidChars(str) == FALSE)
	{
		printf("ContainsInvalidChars == FALSE\n");
		if (!(tetris = CreateTetris(str, 'A')))
		{
			printf("CreateTetris throws an Exception\n");
			free(tetris);
		}
	}
	else
		printf("ContainsInvalidChars throws an Exception\n");
	while (length < 16)
	{
		if (tetris->row[x][y])
			printf("x:[%d] | y:[%d]", x, y);
		x++;
		y++;
		length++;
	}
	return (0);
}
