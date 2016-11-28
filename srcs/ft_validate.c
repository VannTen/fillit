/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:03:49 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/28 17:26:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_validate.h"

t_bool		ft_invalidate_block(t_list *entry)
{
	t_validation	tests[2];
	size_t			function;

	tests[0] = &ContainsInvalidChars;
	tests[1] = NULL;
	function = 0;
	while (tests[function] != NULL)
	{
		if (tests[function]((char*)entry->content))
			return (TRUE);
		function++;
	}
	return (FALSE);
}

t_bool		ft_entry_is_valid(t_list *entry_list)
{
	if (ft_lstcheck(entry_list, ft_invalidate_block) != 0)
		return (FALSE);
	return (TRUE);
}
