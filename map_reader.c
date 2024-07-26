/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 09:57:03 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/26 14:26:30 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	check_map_format(t_game *game, char *argv)
// {
// 	int len;
// 	char *c;

// 	len = ft_strlen(argv) + 1;
// 	ft_printf("argv is %s\n", argv);
// 	ft_printf("len is %d\n", len);
// 	c = ft_strnstr(argv, ".ber\0", len);
// 	ft_printf("c is %s\n", c);
// 	if (c == NULL)
// 	{
// 		ft_printf("The map format must be *.ber\n");
// 		free_and_exit(game, 1);
// 	}
// 	else
// 		return ;
// }

void	check_map_format(t_game *game, char *argv)
{
	char	*end;
	int 	i;

	ft_printf("argv is %s\n", argv);
	end = ft_strrchr(argv, '.');
	i = ft_strncmp(end, ".ber\0", 5);
	if (i == 0)
		return ;
	else
	{
		ft_printf("The map format must be *.ber\n");
		free_and_exit(game, 1);
	}
}

void	map_reader(t_game *game, char **argv)
{
	int 	fd;
	char	*line;
	char	**temp;

	check_map_format(game, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		exit(1);
	}
	game->width = ft_strlen(line) - 1;
	while (line != NULL)
	{
		temp = ft_realloc(game->map, (sizeof(char *) * game->height + 1));
		if (temp == NULL)
		{
			free(line);
			free_and_exit(game, 1);
		}
		game->map = temp;
		game->map[game->height] = line;
		//free(line);
		line = get_next_line(fd);
		game->height++;
	}
	close(fd);
	//FOR PRINTING THE MAP
	// ft_printf("map: \n");
	// int i = 0;
	// while (i < game->height)
	// {
	// 	ft_printf("%s", game->map[i]);
	// 	i++;
	// }`
	// ft_printf("\n");
}
