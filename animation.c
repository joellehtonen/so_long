/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:38:44 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/24 15:59:17 by jlehtone         ###   ########.fr       */
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
	game->player->animation[frame]->instances[0].x = game->player->x;
    game->player->animation[frame]->instances[0].y = game->player->y;
	game->player->animation[frame]->instances[0].enabled = true;
	game->player->frame++;
	if (game->player->frame > 5)
		game->player->frame = 2;
}

void	update_chicken_animation(t_game *game, int number)
{
	int i;
	
	i = 0;
	while (game->chicken->animation[i])
	{
		game->chicken->animation[i]->instances[number].enabled = false;
		i++;
	}
	game->chicken->animation[3]->instances[number].enabled = true;
	mlx_set_instance_depth(&game->chicken->animation[3]->instances[number], 1);
	
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
	if (game->player->frame == 0)
	{
		//game->player->animation_timer = mlx_get_time();
		game->player->animation[0]->instances[0].enabled = true;
		game->player->frame = 1;
	}
	else
	{
		//time = mlx_get_time();
		//if (time > game->player->animation_timer + 1)
		//{
			game->player->animation[1]->instances[0].enabled = true;
			game->player->frame = 0;
		//	game->player->animation_timer = 0;
		//}
	}
}