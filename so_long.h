/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:00:52 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/06 14:13:35 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h> //for what?
# include <stdlib.h> //for what?
# include <stdbool.h> //for what?
# include <fcntl.h> //for o_rdonly

# define IMG_SIZE 64

static mlx_image_t* image;

typedef struct s_game
{
	int 	width;
	int 	height;
	int 	collectables;
	int		exit;
	int		start;
	int		move_count;
	char	**map;
	void	*ground;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collect;
	void	*mlx;
	void	*window;
}	t_game;

void ft_controls(void* param);

#endif