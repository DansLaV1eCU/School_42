/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:47 by llupache          #+#    #+#             */
/*   Updated: 2024/10/27 18:07:58 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static char c = 0;
	static int i = 0;

	if (signum == SIGUSR1)
	{
		c |= (1 << i);
		i++;
	}
	if (i == 8)
	{
		if (c == 0)
			printf("\n");
		printf("%c", c);
		c = 0;
		i = 0;
	}
}

int	main()
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	
	printf("%d", pid);

	signal(SIGINT, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGINT, &action, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
