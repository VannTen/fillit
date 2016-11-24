/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:54:31 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/24 18:27:23 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
typedef struct	s_point
{
	int x;
	int y;
}				t_point;
typedef struct	s_tetris
{
	char		id;
	char		row[4][4];
	t_point		pos;
}				t_tetris;

t_bool			ContainsInvalidChars(char *str);
t_tetris		*CreateTetris(char *str, char id);
#endif
