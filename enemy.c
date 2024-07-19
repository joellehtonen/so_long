/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:13:17 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/19 13:56:25 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void enemy_collision(t_game *game, t_box enemy)
{
	if (check_collision(player, enemy) == TRUE)
	{
		if (game->collected == game->collectables)
			free_and_exit(game, 0);
	}
}

void	chase_player(t_game *game)
{
	t_box	enemy;
	t_box	player;
	
	if (game->player->x > game->enemy->x && (game->imgs->enemy->instances[0].enabled = true))
		game->enemy->x += 6;
    if (game->player->x < game->enemy->x && (game->imgs->enemy->instances[0].enabled = true))
		game->enemy->x -= 6;
    if (game->player->y > game->enemy->y && (game->imgs->enemy->instances[0].enabled = true))
		game->enemy->y += 6;
    if (game->player->y < game->enemy->y && (game->imgs->enemy->instances[0].enabled = true))
		game->enemy->y -= 6;
	enemy = (t_box){game->enemy->x, game->enemy->y, TILE_SIZE, TILE_SIZE};
	enemy_collision(game, enemy);
}

void	spawn_enemy(t_game *game)
{
	int time;
	
	time = mlx_get_time;
	if (time = 3)
		game->imgs->enemy->instances[0].enabled = true;
	chase_player(game);
}
