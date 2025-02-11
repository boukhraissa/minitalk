/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:30:47 by rboukhra          #+#    #+#             */
/*   Updated: 2024/11/20 19:21:17 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int n)
{
	char	buffer[11];
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (n == 0)
	{
		return (write(1, "0", 1));
	}
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n = n / 10;
	}
	i--;
	while (i >= 0)
	{
		count += write (1, &buffer[i], 1);
		i--;
	}
	return (count);
}
