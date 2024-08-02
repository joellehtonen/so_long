/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:59:40 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/09 09:55:46 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_printer(long l)
{
	char	c;
	int		len;
	int		check;

	len = 0;
	if (l < 0)
		l = UINT_MAX + l + 1;
	if (l >= 10)
	{
		check = int_printer(l / 10);
		if (check == -1)
			return (-1);
		else
			len += check;
	}
	c = (l % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_unsigned(unsigned long l)
{
	int	len;

	len = int_printer(l);
	return (len);
}
