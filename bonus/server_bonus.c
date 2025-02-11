/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:13:52 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/11 23:52:18 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	byte_num(unsigned char c)
{
	if (c < 128)
		return (1);
	else if ((c & (0b11100000)) == 0b11000000)
		return (2);
	else if ((c & (0b11110000)) == 0b11100000)
		return (3);
	else if ((c & (0b11111000)) == 0b11110000)
		return (4);
	return (0);
}

int	process_char(int *bits, char *byte, int client_pid, int *pos)
{
	static unsigned char	utf8_buf[4];
	static int				remaining;

	(void)client_pid;
	if (++(*bits) == 8)
	{
		if (*pos == 0)
			remaining = byte_num(*byte);
		utf8_buf[(*pos)++] = *byte;
		if (--remaining == 0)
		{
			utf8_buf[*pos] = '\0';
			ft_printf("%s", utf8_buf);
			*pos = 0;
		}
		if (*byte == '\0')
		{
			ft_printf("\n");
			usleep(100);
			kill(client_pid, SIGUSR2);
		}
		*bits = 0;
		*byte = 0;
	}
	return (0);
}

void	handle_sig(int signum, siginfo_t *info, void *context)
{
	static int			bits;
	static char			byte;
	static pid_t		client_pid;
	static int			pos;

	(void)context;
	if (info->si_pid != client_pid)
	{
		client_pid = info->si_pid;
		bits = 0;
		byte = 0;
		pos = 0;
	}
	if (signum == SIGUSR2)
		byte |= (0b10000000 >> bits);
	if (process_char(&bits, &byte, client_pid, &pos) == 1)
		return ;
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		ft_printf("\033[34m server doesn't take any arguments \033[0m\n");
		return (1);
	}
	ft_printf("Server PID :\033[32m %d \033[0m \n", getpid());
	sa.sa_sigaction = handle_sig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
