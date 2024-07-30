/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_names.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:48:25 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/30 15:30:26 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char	**textures_world(void)
{
	static const char *textures_world[8];
	
	textures_world[0] = "textures/green.png";
	textures_world[1] = "textures/wall_1.png";
	textures_world[2] = "textures/wall_2.png";
	textures_world[3] = "textures/wall_3.png";
	textures_world[4] = "textures/wall_4.png";
	textures_world[5] = "textures/exit_green-ish.png";
	textures_world[6] = "textures/exit_yellow.png";
	textures_world[7] = NULL;
	return (textures_world);
}

const char	**textures_chicken(void)
{
	static const char *textures_chicken[5];

	textures_chicken[0] = "textures/chicken_sit1.png";
	textures_chicken[1] = "textures/chicken_sit2.png";
	textures_chicken[2] = "textures/chicken_die1.png";
	textures_chicken[3] = "textures/chicken_die2.png";
	textures_chicken[4] = NULL;
	return (textures_chicken);
}

const char	**textures_fox(void)
{
	static const char *textures_fox[10];

	textures_fox[0] = "textures/fox_run1.png";
	textures_fox[1] = "textures/fox_run2.png";
	textures_fox[2] = "textures/fox_run3.png";
	textures_fox[3] = "textures/fox_run4.png";
	textures_fox[4] = "textures/fox_run5.png";
	textures_fox[5] = "textures/fox_run6.png";
	textures_fox[6] = "textures/fox_run7.png";
	textures_fox[7] = "textures/fox_run8.png";
	textures_fox[8] = "textures/fox_idle1.png";
	textures_fox[9] = NULL;
	return (textures_fox);
}

const char	**textures_dog(void)
{
	static const char *textures_dog[13];

	textures_dog[0] = "textures/dog_run1.png";
	textures_dog[1] = "textures/dog_run2.png";
	textures_dog[2] = "textures/dog_run3.png";
	textures_dog[3] = "textures/dog_run4.png";
	textures_dog[4] = "textures/dog_run5.png";
	textures_dog[5] = "textures/dog_run6.png";
	textures_dog[6] = "textures/dog_run7.png";
	textures_dog[7] = "textures/dog_run8.png";
	textures_dog[8] = "textures/dog_die1.png";
	textures_dog[9] = "textures/dog_die2.png";
	textures_dog[10] = "textures/dog_die3.png";
	textures_dog[11] = "textures/dog_die4.png";
	textures_dog[12] = NULL;
	return (textures_dog);
}
