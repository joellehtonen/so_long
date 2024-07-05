/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:59:56 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/09 09:13:30 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_void_pointer(void *pointer)
{
	int		len;
	char	format;
	int		check;

	format = 'x';
	len = 0;
	check = ft_string("0x");
	if (check == -1)
		return (check);
	else
		len += check;
	check = ft_hexa((unsigned long)pointer, format);
	if (check == -1)
		return (check);
	else
		len += check;
	return (len);
}
