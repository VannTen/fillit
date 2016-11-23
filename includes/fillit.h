/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:54:31 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/23 14:26:55 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft,h"

typedef struct	s_tetris{
	char		id;
	size_t		shape;
}				t_tetris;

typedef struct	s_link{
	t_tetris	*content;
	s_link		*next;
}				t_link;

#endif
