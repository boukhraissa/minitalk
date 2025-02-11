/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:04:09 by rboukhra          #+#    #+#             */
/*   Updated: 2024/11/22 16:30:21 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *buffer, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, buffer);
	while (*buffer != '\0')
	{
		if (*buffer == '%')
			count += ft_printf_buf(*(++buffer), args);
		else
			count += write(1, buffer, 1);
		if (!*buffer)
		{
			va_end(args);
			return (count - 1);
		}
		buffer++;
	}
	va_end(args);
	return (count);
}
