/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:57:03 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/11 16:25:05 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_line(t_game *game, char *line)
{
	size_t	old_size;
	size_t	new_size;

	if (!line)
		return ;
	old_size = sizeof(char *) * game->height;
	new_size = sizeof(char *) * game->height + 1;
	game->map = ft_realloc(game->map, old_size, new_size);
	if (!game->map)
	{
		free(line);
		free_and_exit(game, 1);
	}
	game->height++;
	game->map[game->height] = line;
	//ft_printf("%s", line);
	ft_printf("%s", game->map[game->height]);
}

int map_reader(t_game *game, char **argv)
{
	int 	fd;
	char	*line;
	int 	i = 0;

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
	while (game->map[game->height])
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
	ft_printf("%s\n", game->map);
	game->width = ft_strlen(&line[0]);
	close(fd);
	return (1);
}
