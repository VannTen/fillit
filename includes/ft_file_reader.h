/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_reader.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:19:09 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/24 13:01:35 by mgautier         ###   ########.fr       */
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

# define BUF_SIZE 20

/*
** Functions
*/

t_list	*open_close_file(char *str);
t_list	*ft_cut_tetriminos(int file_descriptor);
t_bool	ft_validate_block(t_list *entry);
t_bool	ft_entry_is_valid(t_list *entry_list);

#endif
