/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:28:07 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/24 13:27:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

void	ft_test_reader(t_list *entry_list)
{
	ft_lstiter(entry_list, &ft_link_apply);
}

void	ft_link_apply(t_list *elem)
{
	ft_putstr((char*)elem->content);
}
