/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:34:40 by jlehtone          #+#    #+#             */
/*   Updated: 2024/08/03 10:28:43 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	write_moves_to_window(t_game *game)
{
	char		*nbr;
	char		*str;
	mlx_image_t	*image;

	if (game->moves)
		mlx_delete_image(game->mlx, game->moves);
	nbr = ft_itoa(game->move_count);
	str = ft_strjoin("MOVES: ", nbr);
	free(nbr);
	if (str == NULL)
		return ;
	image = mlx_put_string(game->mlx, str,
			game->player->x - 128, game->player->y);
	free(str);
	game->moves = image;
}
