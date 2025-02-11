/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_10.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:01:22 by rboukhra          #+#    #+#             */
/*   Updated: 2024/11/20 20:25:37 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_10(int nb)
{
	char	buffer[12];
	int		count;
	int		i;
	char	c;

	count = 0;
	i = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb == 0)
		buffer[i++] = '0';
	while (nb > 0)
	{
		c = (nb % 10) + '0';
		buffer[i++] = c;
		nb = nb / 10;
	}
	while (--i >= 0)
		count += ft_putchar(buffer[i]);
	return (count);
}
