/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:57:03 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/15 15:21:10 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void map_reader(t_game *game, char **argv)
{
	int 	fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		free_and_exit(game, 1);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1;
	while (line != NULL)
	{
		game->map[game->height] = line;
		//ft_printf("%s", game->map[game->height]);
		//free(line);
		line = get_next_line(fd);
		game->height++;
		game->map = ft_realloc(game->map, game->height);
	}
	close(fd);
}
