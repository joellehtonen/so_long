/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:41:24 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/21 13:38:57 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (!n)
		return (0);
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while ((*a == *b) && (n > 1))
	{
		a++;
		b++;
		n--;
	}
	return (*a - *b);
}
