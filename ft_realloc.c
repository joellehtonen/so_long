/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:46:36 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/26 14:50:11 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *ft_realloc(void *ptr, size_t size) 
{
    void *new_ptr;

    if (ptr == NULL) 
	{
    	ptr = malloc(size);
	 	if (ptr == NULL) 
		{
       		return (NULL);
   		}
		return (ptr);
    }
    if (size == 0) 
	{
        free(ptr);
        return (NULL);
    }
    new_ptr = malloc(size);
    if (new_ptr == NULL) 
	{
        return (NULL);
    }
    ft_memcpy(new_ptr, ptr, size);
    free(ptr);
    return (new_ptr);
}
