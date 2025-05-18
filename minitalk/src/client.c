/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtereshc <dtereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 20:36:54 by dt                #+#    #+#             */
/*   Updated: 2025/05/17 23:08:43 by dtereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_marker = 1;

void	marker_handler(int signum)
{
	if (signum == SIGUSR2)
		g_marker = 1;
}

void	send_message(char *message, int pid)
{
	int	i;
	int	j;

	i = 0;
	while (42)
	{
		j = 0;
		while (j < 8)
		{
			if ((message[i] << j++) & 128)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			g_marker = 0;
			while (!g_marker)
			{
				pause();
			}
		}
		if (message[i] == '\0')
			break ;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	st;

	if (argc != 3)
	{
		printf("Should be 2 args:\n1. Pid of the server\n2. Your message.");
		return (EXIT_FAILURE);
	}
	ft_memset(&st, 0, sizeof(st));
	st.sa_handler = marker_handler;
	st.sa_flags = 0;
	sigaction(SIGUSR2, &st, NULL);
	send_message(argv[2], ft_atoi(argv[1]));
	return (0);
}
