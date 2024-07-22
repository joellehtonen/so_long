/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_names.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:48:25 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/22 10:14:06 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char *texture_names_world(void)
{
	static const char *textures_world[7];
	
	textures_world[0] = "wall_1.png";
	textures_world[1] = "wall_2.png";
	textures_world[2] = "wall_3.png";
	textures_world[3] = "wall_4.png";
	textures_world[4] = "exit_green-ish.png";
	textures_world[5] = "exit_yellow.png";
	textures_world[6] = "green.png";
	return (textures_world);
}

const char *texture_names_animation(void)
{
	static const char *textures_animation[19];

	textures_animation[0] = "fox_sit1.png";
	textures_animation[1] = "fox_sit2.png";
	textures_animation[2] = "fox_run1.png";
	textures_animation[3] = "fox_run2.png";
	textures_animation[4] = "fox_run3.png";
	textures_animation[5] = "fox_run4.png";
	textures_animation[6] = "fox_die1.png";
	textures_animation[7] = "fox_die2.png";
	textures_animation[8] = "chicken_sit1.png";
	textures_animation[9] = "chicken_sit2.png";
	textures_animation[10] = "chicken_die1.png";
	textures_animation[11] = "chicken_die2.png";
	textures_animation[12] = "dog_run1.png";
	textures_animation[13] = "dog_run2.png";
	textures_animation[14] = "dog_run3.png";
	textures_animation[15] = "dog_run4.png";
	textures_animation[16] = "dog_attack1.png";
	textures_animation[17] = "dog_attack2.png";
	textures_animation[18] = "dog_attack3.png";
	return (textures_animation);
}
