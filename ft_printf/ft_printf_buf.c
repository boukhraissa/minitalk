/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:25:48 by rboukhra          #+#    #+#             */
/*   Updated: 2024/11/21 23:21:04 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_buf(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (type == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		count += ft_putnbr_base_10(va_arg(args, int));
	else if (type == 'x')
		count += ft_putnbr_base_hexa(va_arg(args, unsigned int));
	else if (type == 'X')
		count += ft_putnbr_base_hexa2(va_arg(args, unsigned int));
	else if (type == '%')
		count += write(1, "%", 1);
	else if (type == 'p')
		count += ft_print_adress(va_arg(args, void *));
	else if (type == 'u')
		count += ft_printunsigned(va_arg(args, unsigned int));
	else
		count += write(1, &type, 1);
	return (count);
}
