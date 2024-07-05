/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:00:45 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/30 15:43:06 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int		ft_character(char c);
int		ft_hexa(unsigned long l, char format);
int		ft_integer(int i);
int		ft_printf(const char *input, ...);
int		ft_string(char *s);
int		ft_unsigned(unsigned long l);
int		ft_void_pointer(void *pointer);

#endif
