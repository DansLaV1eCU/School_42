/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:47 by llupache          #+#    #+#             */
/*   Updated: 2025/05/18 21:27:39 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_feedback = 1;

void	wait_feedback(void)
{
	while (g_feedback == 0)
	{
		pause();
	}
}

void	change_feedback(int signum)
{
	if (signum == SIGUSR1)
		g_feedback = 1;
}

void	send_message(int pid, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j])
	{
		i = 0;
		while (i < 8)
		{
			if (str[j] & (1 << i++))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			g_feedback = 0;
			wait_feedback();
		}
		j++;
	}
	j = 0;
	while (j++ < 8)
	{
		kill(pid, SIGUSR2);
		g_feedback = 0;
		wait_feedback();
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
		return (ft_printf("Error"));
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("Error"));
	signal(SIGUSR1, change_feedback);
	str = ft_itoa(ft_strlen(argv[2]));
	send_message(pid, str);
	free(str);
	send_message(pid, argv[2]);
	return (0);
}
