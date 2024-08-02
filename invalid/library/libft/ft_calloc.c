/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:41:22 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/21 13:36:58 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*pointer;
	size_t			remaining_memory;
	size_t			index;

	if (count != 0)
	{
		if (size > SIZE_MAX / count)
			return (NULL);
	}
	remaining_memory = (count * size);
	index = 0;
	pointer = malloc(count * size);
	if (pointer == NULL)
		return (NULL);
	while (remaining_memory > 0)
	{
		pointer[index] = 0;
		index++;
		remaining_memory--;
	}
	return ((void *)pointer);
}
