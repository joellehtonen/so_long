/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:57:08 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/21 13:40:52 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		index;

	index = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack != 0 && len > 0)
	{
		while (haystack[index] == needle[index]
			&& needle[index] != '\0' && len > index)
		{
			index++;
			len--;
		}
		if (needle[index] == '\0')
			return ((char *)haystack);
		else
			index = 0;
		haystack++;
		len--;
	}
	return (NULL);
}
