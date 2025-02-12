/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 04:57:47 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/12 17:02:42 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_byte(int signal, siginfo_t *sg, void *old)
{
	static unsigned char	c = 0;
	static int				count = 0;
	static int				client = 0;

	(void)old;
	if (client && client != sg->si_pid)
	{
		ft_printf("\n");
		c = 0;
		count = 0;
	}
	client = sg->si_pid;
	if (signal == SIGUSR2)
		c |= (1 << (7 - count));
	if (++count == 8)
	{
		ft_printf("%c", c);
		if (!c)
		{
			usleep(250);
			usleep(250);
		}
		c = 0;
		count = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sg;
	int					pid;

	(void)av;
	if (ac != 1)
		return (ft_printf("\033[30m THE SERVER DOESN'T TAKE ANY ARGS!\033[0m\n"), 1);
	pid = getpid();
	ft_printf("PID : \033[32m %d \033[0m\n", pid);
	sg.sa_sigaction = print_byte;
	sigemptyset(&sg.sa_mask);
	sg.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sg, NULL);
	sigaction(SIGUSR2, &sg, NULL);
	while (1)
		pause();
	return (0);
}
