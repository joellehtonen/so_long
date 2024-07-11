/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:16:06 by jlehtone          #+#    #+#             */
/*   Updated: 2024/07/11 12:40:02 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	find_newline(char *pile);
char	*free_and_null(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);

#endif