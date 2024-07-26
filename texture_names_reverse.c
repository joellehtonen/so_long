/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_names_reverse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:48:25 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/26 15:27:36 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char **textures_fox_reverse(void)
{
	static const char *textures_fox_reverse[10];

	textures_fox_reverse[0] = "textures/fox_run1_r.png";
	textures_fox_reverse[1] = "textures/fox_run2_r.png";
	textures_fox_reverse[2] = "textures/fox_run3_r.png";
	textures_fox_reverse[3] = "textures/fox_run4_r.png";
	textures_fox_reverse[4] = "textures/fox_run5_r.png";
	textures_fox_reverse[5] = "textures/fox_run6_r.png";
	textures_fox_reverse[6] = "textures/fox_run7_r.png";
	textures_fox_reverse[7] = "textures/fox_run8_r.png";
	textures_fox_reverse[8] = "textures/fox_idle1_r.png";
	textures_fox_reverse[9] = NULL;
	return (textures_fox_reverse);
}

const char **textures_dog_reverse(void)
{
	static const char *textures_dog_reverse[13];

	textures_dog_reverse[0] = "textures/dog_run1_r.png";
	textures_dog_reverse[1] = "textures/dog_run2_r.png";
	textures_dog_reverse[2] = "textures/dog_run3_r.png";
	textures_dog_reverse[3] = "textures/dog_run4_r.png";
	textures_dog_reverse[4] = "textures/dog_run5_r.png";
	textures_dog_reverse[5] = "textures/dog_run6_r.png";
	textures_dog_reverse[6] = "textures/dog_run7_r.png";
	textures_dog_reverse[7] = "textures/dog_run8_r.png";
	textures_dog_reverse[8] = "textures/dog_die1_r.png";
	textures_dog_reverse[9] = "textures/dog_die2_r.png";
	textures_dog_reverse[10] = "textures/dog_die3_r.png";
	textures_dog_reverse[11] = "textures/dog_die4_r.png";
	textures_dog_reverse[12] = NULL;
	return (textures_dog_reverse);
}
