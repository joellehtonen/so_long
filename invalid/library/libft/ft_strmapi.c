/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:32:43 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/21 13:40:24 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*pointer;
	int		len;
	int		index;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	pointer = malloc(sizeof(char) * (len + 1));
	if (!pointer)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		pointer[index] = f(index, s[index]);
		index++;
	}
	pointer[index] = '\0';
	return (pointer);
}
