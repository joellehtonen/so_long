/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:46:36 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/11 14:31:18 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "library/libft/libft.h"

void *ft_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	min_size;
	
	if (new_size == 0)
	{
		free(old_ptr);
		return (old_ptr);
	}
	if (old_ptr == NULL)
	{
		old_ptr = malloc(new_size);
		return (old_ptr);
	}
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	if (new_size > old_size)
		min_size = new_size;
	else
		min_size = old_size;
	ft_memcpy(new_ptr, old_ptr, min_size);
	free(old_ptr);
	return (new_ptr);
}
