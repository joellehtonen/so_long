/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:22 by jlehtone          #+#    #+#             */
/*   Updated: 2024/06/26 10:09:29 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	token_counter(const char *s, char c)
{
	size_t	count;
	size_t	index;

	index = 0;
	if (s[index] == c || s[index] == '\0')
		count = 0;
	else
		count = 1;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			if (s[index + 1] != c && s[index + 1] != '\0')
				count++;
		}
		index++;
	}
	return (count);
}

static size_t	token_len(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	return (len);
}

static void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**splitter(const char *str, char delim, char **array, size_t count)
{
	size_t	index;
	size_t	start;

	index = 0;
	start = 0;
	while (index < count)
	{
		while (str[start] == delim && str[start] != '\0')
			start++;
		array[index] = ft_substr(str, start, token_len(str + start, delim));
		if (!array[index])
		{
			array[index] = NULL;
			free_array(array);
			return (NULL);
		}
		while (str[start] != '\0' && str[start] != delim)
			start++;
		index++;
	}
	array[index] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	token_count;

	if (!s)
		return (NULL);
	token_count = token_counter(s, c);
	result = (char **)malloc(sizeof(char *) * (token_count + 1));
	if (!result)
		return (NULL);
	result = splitter(s, c, result, token_count);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
