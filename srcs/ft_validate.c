/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:03:49 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/28 12:10:58 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_validate.h"

t_bool		ft_validate_block(t_list *entry)
{
	if (ContainsInvalidChars((char*)entry->content))
		return (FALSE);
	else
		return (TRUE);
}

t_bool		ft_entry_is_valid(t_list *entry_list)
{
	t_validation	tests[2];
	size_t			function;

	tests[0] = &ft_validate_block;
	tests[1] = NULL;
	function = 0;
	while (tests[function] != NULL)
	{
		if (ft_lstcheck(entry_list, &ft_validate_block) != 0)
			return (FALSE);
		function++;
	}
	return (TRUE);
}
