/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:13:17 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/30 10:05:20 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void enemy_collision(t_game *game, t_box enemy)
{
	t_box	player;
	
	player = (t_box){game->player->x, game->player->y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, game->enemy->x, game->enemy->y) == TRUE
		|| is_wall(game, game->enemy->x + MOVE_SIZE, game->enemy->y) == TRUE
		|| is_wall(game, game->enemy->x, game->enemy->y + MOVE_SIZE) == TRUE
		|| is_wall(game, game->enemy->x + MOVE_SIZE, game->enemy->y + MOVE_SIZE) == TRUE)
	
	{
		enemy_death(game);
	}
	if (check_collision(player, enemy) == TRUE)
	{
		ft_printf("PLAYER CAUGHT! (the dog is grateful)\n");
		//play animation 
		free_and_exit(game, 0);
	}
}

void	update_enemy_animation(t_game *game, int frame)
{
	int i;
	
	i = 0;
	while (game->enemy->animation[i])
	{
		game->enemy->animation[i]->instances[0].enabled = false;
		game->enemy->animation[i]->instances[0].x = game->enemy->x;
   		game->enemy->animation[i]->instances[0].y = game->enemy->y;
		game->enemy->reverse_animation[i]->instances[0].enabled = false;
		game->enemy->reverse_animation[i]->instances[0].x = game->enemy->x;
   		game->enemy->reverse_animation[i]->instances[0].y = game->enemy->y;
		mlx_set_instance_depth(&game->enemy->animation[i]->instances[0], 3);
		mlx_set_instance_depth(&game->enemy->reverse_animation[i]->instances[0], 3);
		i++;
	}
	if (game->enemy->left == 0)
		game->enemy->animation[frame]->instances[0].enabled = true;
	else
		game->enemy->reverse_animation[frame]->instances[0].enabled = true;
	game->enemy->frame++;
	if (game->enemy->frame > 7)
		game->enemy->frame = 0;
}

static void	chase_player(t_game *game)
{
	t_box	enemy;
	int 	frame;

	frame = game->enemy->frame;
	if (game->enemy->dying == 0)
	{
		if (game->player->x > game->enemy->x)
		{
			game->enemy->animation[frame]->instances[0].x += MOVE_SPEED;
			game->enemy->x += MOVE_SPEED;
			game->enemy->left = 0;
		}
		if (game->player->x < game->enemy->x)
		{
			game->enemy->animation[frame]->instances[0].x -= MOVE_SPEED;
			game->enemy->x -= MOVE_SPEED;
			game->enemy->left = 1;
		}
		if (game->player->y > game->enemy->y)
		{
			game->enemy->animation[frame]->instances[0].y += MOVE_SPEED;
			game->enemy->y += MOVE_SPEED;
		}
		if (game->player->y < game->enemy->y)
		{
			game->enemy->animation[frame]->instances[0].y -= MOVE_SPEED;
			game->enemy->y -= MOVE_SPEED;
		}
		game->enemy->move_count++;	
		if (game->enemy->move_count % 3 == 0)
			update_enemy_animation(game, frame);
	}
	enemy = (t_box){game->enemy->x, game->enemy->y, TILE_SIZE, TILE_SIZE};
	enemy_collision(game, enemy);
}

void	enemy_appears(t_game *game)
{
	double time;
	
	time = mlx_get_time();
	//printf("time is %f\n", time);
	if (time > 4 && time < 5 && game->enemy->active == 0)
	{
		game->enemy->animation[0]->instances[0].enabled = true;
		game->enemy->active = 1;
	}
	if (game->enemy->active == 1)
		chase_player(game);
}
