/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:59:38 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/09 09:53:07 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *s)
{
	int	len;

	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	len = 0;
	while (s[len] != '\0')
		len++;
	return (write(1, s, len));
}
