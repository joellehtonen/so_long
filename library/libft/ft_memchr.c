/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:09:53 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/21 13:38:53 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*pointer;

	a = c;
	pointer = (unsigned char *)s;
	while (n > 1)
	{
		if (*pointer == a)
		{
			return ((void *)pointer);
		}
		pointer++;
		n--;
	}
	return (NULL);
}
