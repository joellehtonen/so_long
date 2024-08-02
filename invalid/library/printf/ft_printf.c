/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehtone <jlehtone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 08:56:49 by jlehtone          #+#    #+#             */
/*   Updated: 2024/05/15 11:41:31 by jlehtone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	function_chooser(const char format, va_list args)
{
	if (format == 'c')
		return (ft_character(va_arg(args, int)));
	else if (format == 's')
		return (ft_string(va_arg(args, char *)));
	else if (format == 'i' || format == 'd')
		return (ft_integer(va_arg(args, int)));
	else if (format == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_hexa(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (ft_void_pointer(va_arg(args, void *)));
	else if (format == '%')
		return (ft_character('%'));
	else
		return (-1);
}

static int	input_printer(const char *input, va_list args, int index, int len)
{
	int	check;

	while (input[index] != '\0')
	{
		if (input[index] == '%')
		{
			check = function_chooser(*(input + index + 1), args);
			if (check == -1)
				return (-1);
			len += check;
			index++;
		}
		else
		{
			check = ft_character(input[index]);
			if (check == -1)
				return (-1);
			len += check;
		}
		index++;
	}
	return (len);
}

int	ft_printf(const char *input, ...)
{
	int		index;
	int		len;
	va_list	args;

	len = 0;
	index = 0;
	va_start(args, input);
	if (input == 0)
		return (-1);
	len = input_printer(input, args, index, len);
	va_end(args);
	return (len);
}
