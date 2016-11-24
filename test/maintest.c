/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:40:05 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/24 13:20:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file_reader.h"
#include "ft_test.h"

int	main(int argc, char **argv)
{
	t_list *entry;

	if (argc != 2)
		return (EXIT_FAILURE);
	entry = open_close_file(argv[1]);
	ft_test_reader(entry);
	return (EXIT_SUCCESS);
}
