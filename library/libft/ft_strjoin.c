/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:41:57 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/21 13:39:58 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pointer;
	size_t	index;
	size_t	s1_len;
	size_t	s2_len;

	index = 0;
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	pointer = malloc(sizeof(char) * ((s1_len + s2_len) + 1));
	if (pointer == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		pointer[index] = *s1;
		s1++;
		index++;
	}
	while (*s2 != '\0')
	{
		pointer[index] = *s2;
		s2++;
		index++;
	}
	pointer[index] = '\0';
	return (pointer);
}
