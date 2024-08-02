/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:38:44 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/02 11:23:39 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_player_animation(t_game *game, int frame)
{
	int	i;

	i = 0;
	while (game->player->animation[i])
	{
		game->player->animation[i]->instances[0].enabled = false;
		game->player->animation[i]->instances[0].x = game->player->x;
		game->player->animation[i]->instances[0].y = game->player->y;
		game->player->rev_anim[i]->instances[0].enabled = false;
		game->player->rev_anim[i]->instances[0].x = game->player->x;
		game->player->rev_anim[i]->instances[0].y = game->player->y;
		mlx_set_instance_depth(&game->player->animation[i]->instances[0], 5);
		mlx_set_instance_depth(&game->player->rev_anim[i]->instances[0], 5);
		i++;
	}
	if (game->player->left == 0)
		game->player->animation[frame]->instances[0].enabled = true;
	else
		game->player->rev_anim[frame]->instances[0].enabled = true;
	game->player->frame++;
	if (game->player->frame > 7)
		game->player->frame = 0;
}

void	update_chicken_animation(t_game *game, int number)
{
	int		i;
	double	time;

	i = 0;
	if (game->chicken->dying == 0)
	{
		game->chicken->animation_timer = mlx_get_time();
		game->chicken->dying = 1;
	}
	while (game->chicken->animation[i])
	{
		game->chicken->animation[i]->instances[number].enabled = false;
		i++;
	}
	game->chicken->animation[3]->instances[number].enabled = true;
	mlx_set_instance_depth(&game->chicken->animation[3]->instances[number], 2);
	time = mlx_get_time();
	// if (time > game->chicken->animation_timer + 0.5)
	// {
	// 	game->chicken->animation[2]->instances[number].enabled = false;
	// 	game->chicken->animation[3]->instances[number].enabled = true;
	// 	mlx_set_instance_depth(&game->chicken->animation[3]->instances[number], 1);
	// 	//break;
	// }
	//}
}

void	idle_animation(t_game *game)
{
	int	i;

	i = 0;
	while (game->player->animation[i])
	{
		game->player->animation[i]->instances[0].enabled = false;
		game->player->animation[i]->instances[0].x = game->player->x;
		game->player->animation[i]->instances[0].y = game->player->y;
		game->player->rev_anim[i]->instances[0].enabled = false;
		game->player->rev_anim[i]->instances[0].x = game->player->x;
		game->player->rev_anim[i]->instances[0].y = game->player->y;
		i++;
	}
	if (game->player->left == 0)
	{
		game->player->animation[8]->instances[0].enabled = true;
	}
	else
	{
		game->player->rev_anim[8]->instances[0].enabled = true;
	}
}
