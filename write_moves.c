/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:34:40 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/31 15:50:48 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_moves_to_window(t_game *game)
{
	char 		*str;
	mlx_image_t	*image;
	
	str = ft_itoa(game->move_count);
	image = mlx_put_string(game->mlx, str, 0, game->height + 1);
	game->moves = image;
	free(str);
}