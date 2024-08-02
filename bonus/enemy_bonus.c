/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:13:17 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/02 09:54:58 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	enemy_collision(t_game *game)
{
	t_box	enemy;
	t_box	player;

	enemy = (t_box){game->enemy->x, game->enemy->y, TILE_SIZE, TILE_SIZE};
	player = (t_box){game->player->x, game->player->y, TILE_SIZE, TILE_SIZE};
	if (is_wall(game, game->enemy->x, game->enemy->y)
		|| is_wall(game, game->enemy->x + MOVE_SIZE, game->enemy->y)
		|| is_wall(game, game->enemy->x, game->enemy->y + MOVE_SIZE)
		|| is_wall(game, game->enemy->x + MOVE_SIZE,
			game->enemy->y + MOVE_SIZE))
	{
		enemy_dies(game);
	}
	if (check_collision(player, enemy))
	{
		ft_printf("PLAYER CAUGHT! (the dog is grateful)\n");
		free_and_exit(game, 0);
	}
}

static void	update_enemy_animation(t_game *game, int frame)
{
	int	i;

	i = 0;
	while (game->enemy->animation[i])
	{
		game->enemy->animation[i]->instances[0].enabled = false;
		game->enemy->animation[i]->instances[0].x = game->enemy->x;
		game->enemy->animation[i]->instances[0].y = game->enemy->y;
		game->enemy->rev_anim[i]->instances[0].enabled = false;
		game->enemy->rev_anim[i]->instances[0].x = game->enemy->x;
		game->enemy->rev_anim[i]->instances[0].y = game->enemy->y;
		mlx_set_instance_depth(&game->enemy->animation[i]->instances[0], 3);
		mlx_set_instance_depth(&game->enemy->rev_anim[i]->instances[0], 3);
		i++;
	}
	if (game->enemy->left == 0)
		game->enemy->animation[frame]->instances[0].enabled = true;
	else
		game->enemy->rev_anim[frame]->instances[0].enabled = true;
	game->enemy->frame++;
	if (game->enemy->frame > 7)
		game->enemy->frame = 0;
}

static void	update_enemy_y_axis(t_game *game)
{
	int		frame;

	frame = game->enemy->frame;
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
}

static void	chase_player(t_game *game)
{
	int		frame;

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
		update_enemy_y_axis(game);
		game->enemy->move_count++;
		if (game->enemy->move_count % 3 == 0)
			update_enemy_animation(game, frame);
	}
	enemy_collision(game);
}

void	enemy_appears(t_game *game)
{
	if (game->move_count == 100 && game->enemy->active == 0)
	{
		game->enemy->animation[0]->instances[0].enabled = true;
		game->enemy->active = 1;
	}
	if (game->enemy->active == 1)
		chase_player(game);
}
