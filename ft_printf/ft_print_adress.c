/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:44:17 by rboukhra          #+#    #+#             */
/*   Updated: 2024/11/23 13:14:58 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_adress(void *n)
{
	int				count;
	unsigned long	address;
	int				i;
	char			buffer[16];
	char			*hex_digits;

	address = (unsigned long)n;
	hex_digits = "0123456789abcdef";
	i = 0;
	count = 0;
	count += write(1, "0x", 2);
	if (address == 0)
	{
		count += write(1, "0", 1);
		return (count);
	}
	while (address > 0)
	{
		buffer[i] = hex_digits[address % 16];
		address = address / 16;
		i++;
	}
	while (--i >= 0)
		count += write(1, &buffer[i], 1);
	return (count);
}
