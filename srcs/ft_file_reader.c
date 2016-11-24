/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:16:18 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/24 13:29:06 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file_reader.h"

t_list		*open_close_file(char *str)
{
	int		file_descriptor;
	t_list	*entry;

	file_descriptor = open(str, O_RDONLY);
	entry = ft_cut_tetriminos(file_descriptor);
	if (close(file_descriptor) == -1)
		return (NULL);
	return (entry);
}

/*
** Do the following :
** read BUF_SIZE characters from the fd (will be defined at 20, the size of a
** Tetriminos)
** Make an allocated copy of the buffer
** Put it at the end of the list
** Return the first link
*/

t_list		*ft_cut_tetriminos(int file_descriptor)
{
	char	buffer[BUF_SIZE + 1];
	int		oct_read;
	t_list	*last_block;
	t_list	*first_block;

	oct_read = 1;
	last_block = NULL;
	first_block = NULL;
	while (oct_read != 0)
	{
		oct_read = read(file_descriptor, buffer, BUF_SIZE);
		if (oct_read == -1)
			ft_error(READ_ERROR);
		buffer[oct_read] = '\0';
		last_block = ft_add_end_list(last_block, buffer, oct_read + 1);
		if (last_block == NULL)
			ft_error(NOT_ENOUGH_MEMORY);
		if (first_block == NULL)
			first_block = last_block;
	}
	return (first_block);
}
/*
t_bool		ft_validate_block(t_list *entry)
{
	if (ContainsInvalidChars((char*)entry->content))
		return (FALSE);
	else
		return (TRUE);
}

t_bool		ft_entry_is_valid(t_list *entry_list)
{
	if (ft_lstcheck(entry_list, &ft_validate_block) != 0)
		return (FALSE);
	else
		return (TRUE);
}
*/
