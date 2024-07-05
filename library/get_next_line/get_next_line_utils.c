/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:16:30 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/16 15:04:16 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_and_null(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

size_t	find_newline(char *pile)
{
	size_t	index;

	index = 0;
	if (!pile || *pile == '\0')
		return (0);
	while (pile[index] != '\0' && pile[index] != '\n')
		index++;
	if (pile[index] == '\n')
		index++;
	return (index);
}

char	*ft_strchr(char *s, int c)
{
	char	a;

	a = c;
	if (!s)
		return (NULL);
	while (*s != '\0' && *s != a)
		s++;
	if (*s == a)
		return (s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
