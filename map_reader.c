/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:57:03 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/11 11:42:19 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	add_line(t_game *game, char *line)
{
	char 	**new_map;
	size_t	old_size;
	size_t	new_size;

	if (!line)
		return (0);
	old_size = sizeof(char *) * (game->height);
	game->height++;
	new_size = sizeof(char *) * (game->height);
	new_map = ft_realloc(game->map, old_size, new_size);
	if (!new_map)
	{
		free(line);
		free_and_exit(game, 1);
	}
	new_map[game->height - 1] = line;
	new_map[game->height] = NULL;
	game->map = new_map;
	return (1);
}

int map_reader(t_game *game, char **argv)
{
	int 	fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		free_and_exit(game, 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		add_line(game, line);
		free(line);
		line = get_next_line(fd);
	}
	game->width = ft_strlen(&line[0]);
	close(fd);
	return (1);
}
