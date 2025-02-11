/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboukhra <rboukhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:55:36 by rboukhra          #+#    #+#             */
/*   Updated: 2025/02/12 00:41:50 by rboukhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int check_args(int ac, char **av)
{
    int         i;
    const char *error_hmer;
    const char *error_ssfer;
    int         pid;

    error_hmer = "\033[31mError: Please provide valid PID and string\n\033[0m";
    error_ssfer = "\033[33mError: PID must be a valid number\n\033[0m";
    if (ac != 3 || !av[1][0] || !av[2][0])
        return(ft_printf("%s", error_hmer), -1);
    i = 0;
    while (av[1][i])
    {
        if (av[1][i] < '0' || av[1][i] > '9')
            return(ft_printf("%s", error_ssfer), -1);
        i++;
    }
    pid = ft_atoi(av[1]);
    if (pid <= 0)
        return(ft_printf("Error: Invalid PID"), -1);
    return (pid);
}
void send_bit(int i, int pid)
{
    if (i == 0)
        kill(pid, SIGUSR1);
    if (i == 1)
        kill (pid, SIGUSR2);
    usleep(500);
}

void send_char(char c, int pid)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        send_bit((c >> i) & 1, pid);
        i--;
    }
}
void message(int signal)
{
    if (signal == SIGUSR2)
        ft_printf("\033[32m message sent\033[0m\n");
}

int main (int ac, char **av)
{
    int pid;
    int i;

    pid = check_args(ac, av);
    if (pid == -1)
        return (1);
    if (kill(pid, 0) != 0)
        return (ft_printf("\033[31mError: Invalid PID\n\033[0m"), 1);
    signal (SIGUSR2, message);
    i = 0;
    while (av[2][i])
    {
        send_char(av[2][i], pid);
        usleep(30);
        i++;
    }
    return (0);
}