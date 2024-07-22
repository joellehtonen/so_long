/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:17:27 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/22 15:18:15 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_images_animation_fox(t_game *game, const char *textures_animation)
{
	int animation_count;
	mlx_texture_t *texture;
	int i;

	animation_count = sizeof(textures_animation) / sizeof(const char *);
	game->animation = malloc(sizeof(t_images_animation) * animation_count);
	if (game->animation == NULL)
	{
		perror("FAILED TO ALLOCATE MEMORY FOR ANIMATION IMAGES\n");
		exit(1);
	}
	i = 0;
	while (i < animation_count)
	{
		texture = mlx_load_png(textures_animation[i]);
		game->animation->images_animation[i] = mlx_texture_to_image(game->mlx, texture);
		mlx_delete_texture(texture);
		i++;
	}
}