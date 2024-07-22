/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_names.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:48:25 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/22 13:11:07 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char *texture_names_world(void)
{
	static const char *textures_world[7];
	
	textures_world[0] = "textures/green.png";
	textures_world[1] = "textures/wall_1.png";
	textures_world[2] = "textures/wall_2.png";
	textures_world[3] = "textures/wall_3.png";
	textures_world[4] = "textures/wall_4.png";
	textures_world[5] = "textures/exit_green-ish.png";
	textures_world[6] = "textures/exit_yellow.png";
	return (textures_world);
}

const char *texture_names_animation(void)
{
	static const char *textures_animation[19];

	textures_animation[0] = "textures/chicken_sit1.png";
	textures_animation[1] = "textures/chicken_sit2.png";
	textures_animation[2] = "textures/chicken_die1.png";
	textures_animation[3] = "textures/chicken_die2.png";
	textures_animation[4] = "textures/fox_sit1.png";
	textures_animation[5] = "textures/fox_sit2.png";
	textures_animation[6] = "textures/fox_run1.png";
	textures_animation[7] = "textures/fox_run2.png";
	textures_animation[8] = "textures/fox_run3.png";
	textures_animation[9] = "textures/fox_run4.png";
	textures_animation[10] = "textures/fox_die1.png";
	textures_animation[11] = "textures/fox_die2.png";
	textures_animation[12] = "textures/dog_run1.png";
	textures_animation[13] = "textures/dog_run2.png";
	textures_animation[14] = "textures/dog_run3.png";
	textures_animation[15] = "textures/dog_run4.png";
	textures_animation[16] = "textures/dog_attack1.png";
	textures_animation[17] = "textures/dog_attack2.png";
	textures_animation[18] = "textures/dog_attack3.png";
	//textures_animation[19] = "textures/dog_die1.png";
	//textures_animation[20] = "textures/dog_die2.png";
	//textures_animation[21] = "textures/dog_die3.png";
	return (textures_animation);
}
