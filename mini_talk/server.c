/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:47 by llupache          #+#    #+#             */
/*   Updated: 2025/05/18 21:27:09 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	find_index(char *message)
{
	int	i;

	i = 0;
	while (message[i])
		i++;
	return (i);
}

void	make_len(int signum, int pid, int *len, char **message)
{
	static char	c = 0;
	static int	i = 0;

	if (signum == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			*len = ft_atoi(*message);
			free(*message);
			*message = NULL;
		}
		if (*message)
			(*message)[find_index(*message)] = c;
		c = 0;
		i = 0;
	}
	kill(pid, SIGUSR1);
}

void	add_char(int signum, char **message, int pid, int *len)
{
	static char	c = 0;
	static int	i = 0;

	if (signum == SIGUSR1)
	{
		c |= (1 << i);
	}
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			ft_printf("\nYou got a new message: %s\n", *message);
			free(*message);
			*message = NULL;
			*len = 0;
		}
		if (*message)
			(*message)[find_index(*message)] = c;
		c = 0;
		i = 0;
	}
	usleep(50);
	kill(pid, SIGUSR1);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	*message = NULL;
	static int	len = 0;

	(void)context;
	if (len == 0)
	{
		if (message == NULL)
			message = (char *)ft_calloc(1024, 8);
		make_len(signum, info->si_pid, &len, &message);
	}
	else
	{
		if (message == NULL)
			message = (char *)ft_calloc(len, 8);
		add_char(signum, &message, info->si_pid, &len);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sg;

	ft_memset(&sg, 0, sizeof(sg));
	pid = getpid();
	ft_printf("%d\n", pid);
	sg.sa_sigaction = handler;
	sg.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sg, NULL);
	sigaction(SIGUSR2, &sg, NULL);
	while (1)
		pause();
	return (0);
}
