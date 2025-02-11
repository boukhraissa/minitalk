/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:13:25 by rboukhra          #+#    #+#             */
/*   Updated: 2024/11/20 20:30:57 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *buffer, ...);
int				ft_printf_buf(char type, va_list args);
int				ft_putchar(int c);
int				ft_putstr(char *str);
int				ft_putnbr_base_10(int nb);
int				ft_putnbr_base_hexa(unsigned int nb);
int				ft_putnbr_base_hexa2(unsigned int nb);
int				ft_printunsigned(unsigned int n);
int				ft_print_adress(void *n);

#endif