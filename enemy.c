/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:13:17 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/22 12:18:23 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void enemy_collision(t_game *game, t_box enemy)
{
	t_box	player;

	player = (t_box){game->player->x, game->player->y, TILE_SIZE, TILE_SIZE};
	// if (is_wall(game, game->enemy->x, game->enemy->y) == TRUE)
	// {
	// 	//enemy dies
	// }
	if (check_collision(player, enemy) == TRUE)
	{
		//ft_printf("PLAYER CAUGHT!\n");
		//play animation 
		free_and_exit(game, 0);
	}
}

static void	chase_player(t_game *game)
{
	t_box	enemy;

	if (game->player->x > game->enemy->x)
	{
		game->imgs->enemy->instances[0].x += 4;
		game->enemy->x += 4;
	}
	if (game->player->x < game->enemy->x)
	{
		game->imgs->enemy->instances[0].x -= 4;
		game->enemy->x -= 4;
	}
	if (game->player->y > game->enemy->y)
	{
		game->imgs->enemy->instances[0].y += 4;
		game->enemy->y += 4;
	}
	if (game->player->y < game->enemy->y)
	{
		game->imgs->enemy->instances[0].y -= 4;
		game->enemy->y -= 4;
	}
	enemy = (t_box){game->enemy->x, game->enemy->y, TILE_SIZE, TILE_SIZE};
	enemy_collision(game, enemy);
}

void	enemy_appears(t_game *game)
{
	double time;
	
	time = mlx_get_time();
	//printf("time is %f\n", time);
	if (time > 4 && game->enemy->active == 0)
	{
		game->imgs->enemy->instances[0].enabled = true;
		game->enemy->active = 1;
	}
	if (game->enemy->active == 1)
		chase_player(game);
}

void	ready_enemy(t_game *game, int x, int y)
{
	game->player->x = x * TILE_SIZE;
	game->player->y = y * TILE_SIZE;
	game->enemy->x = game->player->x;
	game->enemy->y = game->player->y;
	game->imgs->enemy->instances[0].enabled = false;
}
