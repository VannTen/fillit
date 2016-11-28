/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:17:00 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/28 12:11:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALIDATE_H
# define FT_VALIDATE_H

# include "libft.h"
# include "ft_checker.h"

typedef t_bool	(*t_validation)(t_list *entry);

t_bool	ft_validate_block(t_list *entry);
t_bool	ft_entry_is_valid(t_list *entry_list);

#endif
