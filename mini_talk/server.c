/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:06:47 by llupache          #+#    #+#             */
/*   Updated: 2025/05/17 21:16:42 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	add_char(int signum, struct string_info *info)
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
			ft_printf("\n");
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static struct t_info information;
	char	*str;

	str = (char *)ft_calloc(1024, 8);
	information.str = str;
	information.index = 0;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	st;

	memset(&sa, 0, sizeof(sa));
	pid = getpid();
	ft_printf("%d\n", pid);
	st.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&(st.sa_mask));
	sigaddset(st.sa_mask, SIGUSR1);
	sigaddset(st.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &st, NULL);
	sigaction(SIGUSR2, &st, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
