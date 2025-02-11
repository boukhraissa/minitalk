/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_hexa2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:16:54 by rboukhra          #+#    #+#             */
/*   Updated: 2024/11/21 16:31:18 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_hexa2(unsigned int nb)
{
	char	*base;
	char	buffer[12];
	int		count;
	int		i;
	char	c;

	i = 0;
	count = 0;
	base = "0123456789ABCDEF";
	if (nb == 0)
		buffer[i++] = '0';
	while (nb > 0)
	{
		c = base[nb % 16];
		buffer[i++] = c;
		nb = nb / 16;
	}
	while (--i >= 0)
		count += ft_putchar(buffer[i]);
	return (count);
}
