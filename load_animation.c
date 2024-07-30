/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:17:27 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/30 15:52:23 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upload_player_and_enemy_animations_reverse(t_game *game, int x, int y)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (game->player->rev_anim[count] != NULL)
		count++;
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->player->rev_anim[i],
			x * TILE_SIZE, y * TILE_SIZE);
		game->player->rev_anim[i]->instances[0].enabled = false;
		i++;
	}
	i = 0;
	count = 0;
	while (game->enemy->rev_anim[count] != NULL)
		count++;
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->enemy->rev_anim[i],
			x * TILE_SIZE, y * TILE_SIZE);
		game->enemy->rev_anim[i]->instances[0].enabled = false;
		i++;
	}
}

void	upload_player_and_enemy_animations(t_game *game, int x, int y)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (game->player->animation[count] != NULL)
		count++;
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->player->animation[i],
			x * TILE_SIZE, y * TILE_SIZE);
		game->player->animation[i]->instances[0].enabled = false;
		i++;
	}
	game->player->animation[0]->instances[0].enabled = true;
	i = 0;
	count = 0;
	while (game->enemy->animation[count] != NULL)
		count++;
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->enemy->animation[i],
			x * TILE_SIZE, y * TILE_SIZE);
		game->enemy->animation[i]->instances[0].enabled = false;
		i++;
	}
	upload_player_and_enemy_animations_reverse(game, x, y);
}

void	upload_chicken_animations(t_game *game, int x, int y, int number)
{
	int	count;
	int	i;
	
	i = 0;
	count = 0;
	while (game->chicken->animation[count] != NULL)
		count++;
	while (i < count)
	{
		mlx_image_to_window(game->mlx, game->chicken->animation[i],
			x * TILE_SIZE, y * TILE_SIZE);
		game->chicken->animation[i]->instances[number].enabled = false;
		i++;
	}
	game->chicken->animation[0]->instances[number].enabled = true;
}
