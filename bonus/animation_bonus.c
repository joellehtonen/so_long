/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:38:44 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/07 09:31:29 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_run_animation(t_game *game, int frame)
{
	int	i;

	i = 0;
	while (game->player->anim[i])
	{
		game->player->anim[i]->instances[0].enabled = false;
		game->player->anim[i]->instances[0].x = game->player->x;
		game->player->anim[i]->instances[0].y = game->player->y;
		game->player->rev_anim[i]->instances[0].enabled = false;
		game->player->rev_anim[i]->instances[0].x = game->player->x;
		game->player->rev_anim[i]->instances[0].y = game->player->y;
		mlx_set_instance_depth(&game->player->anim[i]->instances[0], 5);
		mlx_set_instance_depth(&game->player->rev_anim[i]->instances[0], 5);
		i++;
	}
	if (game->player->left == 0)
		game->player->anim[frame]->instances[0].enabled = true;
	else
		game->player->rev_anim[frame]->instances[0].enabled = true;
	game->player->frame++;
	if (game->player->frame > 7)
		game->player->frame = 0;
}

void	chicken_dies_animation(t_game *game, int number)
{
	int		i;

	i = 0;
	while (game->chicken->anim[i])
	{
		game->chicken->anim[i]->instances[number].enabled = false;
		i++;
	}
	game->chicken->anim[2]->instances[number].enabled = true;
	mlx_set_instance_depth(&game->chicken->anim[2]->instances[number], 2);
}

void	chicken_idle_animation(t_game *game)
{
	static double	last_time;
	double			timer;
	int				i;

	timer = mlx_get_time();
	if (timer - last_time > 0.5)
	{
		i = 0;
		while (i < game->collectables)
		{
			if (game->chicken->anim[0]->instances[i].enabled)
			{
				game->chicken->anim[0]->instances[i].enabled = false;
				game->chicken->anim[1]->instances[i].enabled = true;
			}
			else if (game->chicken->anim[1]->instances[i].enabled)
			{
				game->chicken->anim[1]->instances[i].enabled = false;
				game->chicken->anim[0]->instances[i].enabled = true;
			}
			i++;
		}
		last_time = timer;
	}
}

void	player_idle_animation(t_game *game)
{
	int	i;

	i = 0;
	while (game->player->anim[i])
	{
		game->player->anim[i]->instances[0].enabled = false;
		game->player->anim[i]->instances[0].x = game->player->x;
		game->player->anim[i]->instances[0].y = game->player->y;
		game->player->rev_anim[i]->instances[0].enabled = false;
		game->player->rev_anim[i]->instances[0].x = game->player->x;
		game->player->rev_anim[i]->instances[0].y = game->player->y;
		i++;
	}
	if (game->player->left == 0)
	{
		game->player->anim[8]->instances[0].enabled = true;
	}
	else
	{
		game->player->rev_anim[8]->instances[0].enabled = true;
	}
}
