/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:50:51 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/31 10:06:36 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char	**textures_dog(void)
{
	static const char	*textures_dog[13];

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

const char	**textures_dog_reverse(void)
{
	static const char	*textures_dog_reverse[13];

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
