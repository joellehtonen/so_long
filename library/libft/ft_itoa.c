/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:15:02 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/21 13:38:36 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_counter(int num)
{
	int	len;

	len = 0;
	if (num < 0)
		len++;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*pointer;
	int		len;
	int		sign;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	if (!n)
		return (NULL);
	len = int_counter(n);
	pointer = malloc(sizeof(char) * (len + 1 + sign));
	if (!pointer)
		return (NULL);
	*(pointer + len + sign) = '\0';
	while (len--)
	{
		*(pointer + len + sign) = n % 10 + '0';
		n = n / 10;
	}
	if (sign == 1)
		*pointer = '-';
	return (pointer);
}
