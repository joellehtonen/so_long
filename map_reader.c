/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:57:03 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/18 10:23:26 by jlehtone         ###   ########.fr       */
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
	// game->map = malloc(sizeof(char *) * (game->height + 1));
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1;
	while (line != NULL)
	{
		game->map = realloc(game->map, (sizeof(char *) * game->height + 1)); //remember to change to ft_realloc
		game->map[game->height] = line;
		//ft_printf("new line: \n%s", game->map[game->height]);
		//free(line);
		line = get_next_line(fd);
		game->height++;
	}
	close(fd);
	// //FOR PRINTING THE MAP
	// ft_printf("\n");
	// ft_printf("map: \n");
	// int i = 0;
	// while (i < game->height)
	// {
	// 	ft_printf("%s", game->map[i]);
	// 	i++;
	// }
	// ft_printf("\n");
}
