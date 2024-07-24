/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:38:44 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/24 13:35:09 by jlehtone         ###   ########.fr       */
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
		i++;
	}
	game->player->animation[frame]->instances[0].enabled = true;
	game->player->frame++;
	if (game->player->frame > 5)
		game->player->frame = 2;
}

// void idle_animation(t_game *game)
// {
// 	int i;

// 	i = 0;
// 	if (game->player->frame == 0)
// 	{
// 		while (game->player->animation[i] != NULL)
// 		{
// 			game->player->animation[i]->instances[0].enabled = false;
// 			i++;
// 		}
// 		game->player->animation[0]->instances[0].enabled = true;
// 	}
// 	else
// 	{
// 		while (game->player->animation[i] != NULL)
// 		{
// 			game->player->animation[i]->instances[0].enabled = false;
// 			i++;
// 		}
// 		game->player->animation[1]->instances[0].enabled = true;
// 		game->player->frame = 1;
// 	}
// }