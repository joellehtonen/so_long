/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:57:03 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/05 13:49:35 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map == NULL)
		return ;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

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

// static void	check_map_size(t_game *game)
// {
// 	int		monitor_width;
// 	int		monitor_height;

// 	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
// 	ft_printf("monitor width is %d\n", monitor_width);
// 	ft_printf("monitor height is %d\n", monitor_height);
// 	if (monitor_width == 0 || monitor_height == 0)
// 	{
// 		display_error(game, "Failed to retrieve monitor size");
// 		return;
// 	}
// 	if (game->height > (monitor_height / TILE_SIZE)
// 		|| game->width > (monitor_width / TILE_SIZE))
// 	{
// 		display_error(game, "The map is too big");
// 	}
// 	if (game->height < 3 || game->width < 5)
// 		display_error(game, "The map is empty or too small");
// }

static void	check_map_size(t_game *game)
{
	if (game->height > (MAX_HEIGHT / TILE_SIZE)
		|| game->width > (MAX_WIDTH / TILE_SIZE))
	{
		display_error(game, "The map is too big");
	}
	if (game->height < 3 || game->width < 5)
		display_error(game, "The map is empty or too small");
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
	check_map_size(game);
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
