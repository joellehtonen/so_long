/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flip_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:41:46 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/25 12:52:49 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t *flip_images(mlx_image_t *original)
{
	mlx_image_t *flipped;
	int 		x;
	int			y;

	// flipped = malloc(sizeof(mlx_image_t));
	// if (flipped == NULL)
	// {
	// 	exit(1);
	// }
	flipped->pixels = malloc(original->width * original->height * 4);
	if (flipped->pixels == NULL)
	{
		free(flipped);
		exit(1);
	}
	y = 0;
	while (y < flipped->height)
	{
		x = 0;
		while (x < flipped->width)
		y++;
	}
}
