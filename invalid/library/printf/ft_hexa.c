/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:59:51 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/09 09:55:29 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned long l, char format)
{
	char	*base;
	int		len;
	int		check;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (l >= 16)
	{
		check = ft_hexa(l / 16, format);
		if (check == -1)
			return (-1);
		else
			len += check;
	}
	if (ft_character(base[l % 16]) == -1)
		return (-1);
	len++;
	return (len);
}
