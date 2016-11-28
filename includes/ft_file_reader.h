/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_reader.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:19:09 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/28 12:05:13 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_READER_H
# define FT_FILE_READER_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "fillit.h"
# include "ft_checker.h"
# include "ft_error.h"
# include "ft_validate.h"

# define BUF_SIZE 21

/*
** Functions
*/

t_list	*open_close_file(char *str);
t_list	*ft_cut_tetriminos(int file_descriptor);

#endif
