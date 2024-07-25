/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:46:36 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/25 12:57:50 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/libft/libft.h"

void *ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
	{
		ptr = malloc(size);
		return (ptr);
	}
	if (size == 0)
		return (ptr);
	new_ptr = malloc(size);
	ft_memcpy(new_ptr, ptr, size);
	return (new_ptr);
}

// void	*ft_realloc(void *old_ptr, size_t new_size)
// {
// 	void	*new_ptr;
// 	size_t	old_size;
	
// 	if (new_size == 0)
// 	{
// 		free(old_ptr);
// 		return (NULL);
// 	}
// 	if (old_ptr == NULL)
// 	{	
// 		old_ptr = malloc(new_size);
// 		return (old_ptr);
// 	}
// 	old_size = ft_strlen(old_ptr) + 1;
// 	if (new_size <= old_size)
// 		return (old_ptr);
// 	new_ptr = malloc(new_size);
// 	if (new_ptr == NULL)
// 		return (NULL);
// 	ft_memcpy(new_ptr, old_ptr, old_size);
// 	free(old_ptr);
// 	return (new_ptr);
// }

// void *ft_realloc(void *old_ptr, size_t old_size, size_t new_size)
// {
// 	void	*new_ptr;
// 	size_t	min_size;

// 	if (new_size == 0)
// 	{
// 		free(old_ptr);
// 		return (NULL);
// 	}
// 	if (old_ptr == NULL)
// 	{
// 		old_ptr = malloc(new_size);
// 		return (old_ptr);
// 	}
// 	new_ptr = malloc(new_size);
// 	if (new_ptr == NULL)
// 		return (NULL);
// 	if (old_size < new_size)
// 		min_size = old_size;
// 	else
// 		min_size = new_size;
// 	ft_memcpy(new_ptr, old_ptr, min_size);
// 	free(old_ptr);
// 	return (new_ptr);
// }
