/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:01:05 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/21 13:40:56 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*latest;

	latest = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			(latest = (char *)s);
		}
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (latest);
}
