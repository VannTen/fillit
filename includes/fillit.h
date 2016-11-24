/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:54:31 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/24 13:10:21 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>

typedef t_bool	t_shape[4][4];
typedef struct	s_point
{
	int x;
	int y;
}				t_point;
typedef struct	s_tetris
{
	char		id;
	size_t		shape;
	t_point		position;
}				t_tetris;

#endif
