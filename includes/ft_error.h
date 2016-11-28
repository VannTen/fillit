/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:18:35 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/28 12:12:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "libft.h"

typedef enum	e_error
{
	READ_ERROR,
	NOT_ENOUGH_MEMORY,
	INVALID_ENTRY,
}				t_error;

void	ft_error(t_error value);

#endif
