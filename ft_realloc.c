/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:46:36 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/15 09:52:33 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "library/libft/libft.h"

void	*ft_realloc(void *old_ptr, size_t new_size)
{
	char	*new_ptr;
	size_t	old_size;

	if (old_ptr == 0)
	{	
		old_ptr = malloc(new_size);
		return (old_ptr);
	}
	old_size = sizeof(old_ptr);
	if (new_size <= old_size)
		return (old_ptr);
	new_ptr = malloc(new_size);
	ft_memcpy(old_ptr, new_ptr, old_size);
	free(old_ptr);
	return (new_ptr);
}
