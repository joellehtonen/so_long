/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:46:04 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/16 16:22:35 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*create_new_pile(char *pile)
{
	size_t	index_a;
	size_t	index_b;
	size_t	len;
	char	*new_pile;

	len = ft_strlen(pile);
	index_a = find_newline(pile);
	if (!pile[index_a])
	{
		pile = free_and_null(pile);
		return (NULL);
	}
	index_b = 0;
	new_pile = (char *)malloc(sizeof(char) * (len - index_a + 1));
	if (!new_pile)
	{
		pile = free_and_null(pile);
		return (NULL);
	}
	while (pile[index_a] != '\0')
		new_pile[index_b++] = pile[index_a++];
	new_pile[index_b] = '\0';
	free(pile);
	pile = NULL;
	return (new_pile);
}

static char	*write_line(char *pile)
{
	char	*line;
	size_t	index;

	index = 0;
	if (!pile || !*pile)
		return (NULL);
	index = find_newline(pile);
	line = (char *)malloc(sizeof(char) * (index + 1));
	if (!line)
		return (NULL);
	index = 0;
	while (pile[index] != '\0' && pile[index] != '\n')
	{
		line[index] = pile[index];
		index++;
	}
	if (pile[index] == '\n')
	{
		line[index] = '\n';
		index++;
	}
	line[index] = '\0';
	return (line);
}

static char	*add_to_pile(char *pile, char *text)
{
	size_t	index;
	size_t	len;
	char	*new_pile;

	index = 0;
	if (text == NULL || *text == '\0')
		return (pile);
	len = ft_strlen(pile) + ft_strlen(text);
	new_pile = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_pile)
	{
		free(pile);
		return (NULL);
	}
	while (pile != NULL && pile[index] != '\0')
	{
		new_pile[index] = pile[index];
		index++;
	}
	while (*text != '\0')
		new_pile[index++] = *text++;
	new_pile[index] = '\0';
	free(pile);
	return (new_pile);
}

static char	*read_line(int fd, char *pile)
{
	char		text[BUFFER_SIZE + 1];
	int			bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(pile, '\n'))
	{
		bytes_read = read(fd, text, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			pile = free_and_null(pile);
			return (NULL);
		}
		text[bytes_read] = '\0';
		pile = add_to_pile(pile, text);
	}
	return (pile);
}

char	*get_next_line(int fd)
{
	static char	*pile[MAX_FD];
	char		*line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	pile[fd] = read_line(fd, pile[fd]);
	line = write_line(pile[fd]);
	if (!line)
	{
		pile[fd] = free_and_null(pile[fd]);
		return (NULL);
	}
	pile[fd] = create_new_pile(pile[fd]);
	return (line);
}
