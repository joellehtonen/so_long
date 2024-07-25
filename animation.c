/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:38:44 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/25 12:04:29 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	update_player_animation(t_game *game, int frame)
{
	int i;
	
	i = 0;
	while (game->player->animation[i])
	{
		game->player->animation[i]->instances[0].enabled = false;
		game->player->animation[i]->instances[0].x = game->player->x;
   		game->player->animation[i]->instances[0].y = game->player->y;
		i++;
	}
	mlx_set_instance_depth(&game->player->animation[frame]->instances[0], 5);
	game->player->animation[frame]->instances[0].enabled = true;
	game->player->frame++;
	if (game->player->frame > 7)
		game->player->frame = 0;
}

void	update_chicken_animation(t_game *game, int number)
{
	int i;
	double time;
	
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
	mlx_set_instance_depth(&game->chicken->animation[3]->instances[number], 1);
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

void	update_enemy_animation(t_game *game, int frame)
{
	int i;
	
	i = 0;
	while (game->enemy->animation[i])
	{
		game->enemy->animation[i]->instances[0].enabled = false;
		game->enemy->animation[i]->instances[0].x = game->enemy->x;
   		game->enemy->animation[i]->instances[0].y = game->enemy->y;
		i++;
	}
	game->enemy->animation[frame]->instances[0].enabled = true;
	mlx_set_instance_depth(&game->enemy->animation[0]->instances[0], 2);
	game->enemy->frame++;
	if (game->enemy->frame > 7)
		game->enemy->frame = 0;
}

void idle_animation(t_game *game)
{
	int i;
	//int time;

	i = 0;
	while (game->player->animation[i])
	{
		game->player->animation[i]->instances[0].enabled = false;
		game->player->animation[i]->instances[0].x = game->player->x;
   		game->player->animation[i]->instances[0].y = game->player->y;
		i++;
	}
	game->player->animation[8]->instances[0].enabled = true;
}