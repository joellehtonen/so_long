/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:50:01 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/21 13:40:02 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen((char *)dst);
	s_len = ft_strlen((char *)src);
	if (!dstsize)
		return (s_len);
	if (dstsize <= d_len)
		return (s_len + dstsize);
	while (*dst != '\0' && dstsize > 1)
	{
		dst++;
		dstsize--;
	}
	while (*src != '\0' && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (d_len + s_len);
}
