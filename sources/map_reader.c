/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:57:03 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/02 10:42:23 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_format(t_game *game, char *argv)
{
	char	*end;
	int		i;

	end = ft_strrchr(argv, '.');
	if (end == NULL)
		display_error(game, "The argument is in wrong format");
	i = ft_strncmp(end, ".ber\0", 5);
	if (i == 0)
		return ;
	else
		display_error(game, "The map format must be *.ber");
}

void	get_map_size(t_game *game, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		display_error(game, "Unable to read the file");
	line = get_next_line(fd);
	game->width = ft_strlen(line) - 1;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		game->height++;
	}
	close(fd);
	if (game->height > (MAX_HEIGHT / TILE_SIZE)
		|| game->width > (MAX_WIDTH / TILE_SIZE))
	{
		display_error(game, "The map is too big");
	}
	if (game->height < 3 || game->width < 5)
		display_error(game, "The map is too small");
}

void	map_reader(t_game *game, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		display_error(game, "Unable to read the file");
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (game->map == NULL)
		display_error(game, "Malloc failed");
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		display_error(game, "The file is empty");
	}
	i = 0;
	while (line != NULL)
	{
		game->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}
