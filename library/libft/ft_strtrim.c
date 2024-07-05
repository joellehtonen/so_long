/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:05:47 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/21 13:41:03 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	set_checker(const char *to_check, const char *set)
{
	while (*set != '\0')
	{
		if (*set == *to_check)
			return (1);
		set++;
	}
	return (0);
}

static	size_t	character_counter_start(char const *str, char const *set)
{
	size_t	counter;

	counter = 0;
	while (set_checker(str, set) == 1)
	{
		counter++;
		str++;
	}
	return (counter);
}

static	size_t	character_counter_end(char const *str, char const *set)
{
	size_t	counter;

	counter = 0;
	while (*str != '\0')
		str++;
	str--;
	while (set_checker(str, set) == 1)
	{
		counter++;
		str--;
	}
	return (counter);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*pointer;
	size_t	index;
	size_t	s_len;
	size_t	counter_start;
	size_t	counter_end;

	if (!s1 || !set)
		return (NULL);
	s_len = ft_strlen((char *)s1);
	counter_start = character_counter_start(s1, set);
	counter_end = character_counter_end(s1, set);
	if ((counter_start + counter_end) > s_len)
		s_len = (counter_start + counter_end);
	pointer = malloc(sizeof(char)
			* (s_len - counter_start - counter_end) + 1);
	if (pointer == NULL)
		return (NULL);
	s1 = s1 + counter_start;
	index = 0;
	while ((s_len - counter_start - counter_end) > index)
		pointer[index++] = *s1++;
	pointer[index] = '\0';
	return (pointer);
}
