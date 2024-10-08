/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_death_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:13:17 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/07 09:34:33 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	enemy_death_animation_reverse(t_game *game, int frame)
{
	double	time;

	game->enemy->rev_anim[frame]->instances[0].enabled = true;
	time = mlx_get_time();
	if (time > game->enemy->animation_timer + 0.5)
	{
		game->enemy->rev_anim[frame]->instances[0].enabled = false;
		frame++;
		game->enemy->rev_anim[frame]->instances[0].enabled = true;
	}
	if (time > game->enemy->animation_timer + 0.6)
	{
		game->enemy->rev_anim[frame]->instances[0].enabled = false;
		frame++;
		game->enemy->rev_anim[frame]->instances[0].enabled = true;
	}
	if (time > game->enemy->animation_timer + 0.7)
	{
		game->enemy->rev_anim[frame]->instances[0].enabled = false;
		frame++;
		game->enemy->rev_anim[frame]->instances[0].enabled = true;
		mlx_set_instance_depth(&game->enemy->rev_anim[frame]->instances[0], 4);
		game->enemy->active = 0;
	}
}

static void	enemy_death_animation(t_game *game, int frame)
{
	double	time;

	game->enemy->anim[frame]->instances[0].enabled = true;
	time = mlx_get_time();
	if (time > game->enemy->animation_timer + 0.5)
	{
		game->enemy->anim[frame]->instances[0].enabled = false;
		frame++;
		game->enemy->anim[frame]->instances[0].enabled = true;
	}
	if (time > game->enemy->animation_timer + 0.6)
	{
		game->enemy->anim[frame]->instances[0].enabled = false;
		frame++;
		game->enemy->anim[frame]->instances[0].enabled = true;
	}
	if (time > game->enemy->animation_timer + 0.7)
	{
		game->enemy->anim[frame]->instances[0].enabled = false;
		frame++;
		game->enemy->anim[frame]->instances[0].enabled = true;
		mlx_set_instance_depth(&game->enemy->anim[frame]->instances[0], 4);
		game->enemy->active = 0;
	}
}

void	enemy_dies(t_game *game)
{
	int		i;
	int		frame;

	i = 0;
	frame = game->enemy->frame;
	if (game->enemy->dying == 0)
	{
		game->enemy->animation_timer = mlx_get_time();
		game->enemy->dying = 1;
	}
	while (game->enemy->anim[i])
	{
		game->enemy->anim[i]->instances[0].enabled = false;
		game->enemy->rev_anim[i]->instances[0].enabled = false;
		i++;
	}
	frame = 8;
	if (game->enemy->left == 0)
		enemy_death_animation(game, frame);
	else
		enemy_death_animation_reverse(game, frame);
}
