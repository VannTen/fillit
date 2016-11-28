/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:17:00 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/28 17:26:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALIDATE_H
# define FT_VALIDATE_H

# include "libft.h"
# include "ft_checker.h"
# include "ft_error.h"

typedef t_bool	(*t_validation)(char *str);

t_bool	ft_invalidate_block(t_list *entry);
t_bool	ft_entry_is_valid(t_list *entry_list);

#endif
