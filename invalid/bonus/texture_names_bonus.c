/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_names_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:23:09 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/01 12:37:56 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

const char	**textures_fox(void)
{
	static const char	*textures_fox[10];

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

const char	**textures_fox_reverse(void)
{
	static const char	*textures_fox_reverse[10];

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

const char	**textures_chicken(void)
{
	static const char	*textures_chicken[5];

	textures_chicken[0] = "textures/chicken_sit1.png";
	textures_chicken[1] = "textures/chicken_sit2.png";
	textures_chicken[2] = "textures/chicken_die1.png";
	textures_chicken[3] = "textures/chicken_die2.png";
	textures_chicken[4] = NULL;
	return (textures_chicken);
}