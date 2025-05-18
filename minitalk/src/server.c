/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtereshc <dtereshc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:14:35 by dt                #+#    #+#             */
/*   Updated: 2025/05/17 23:10:43 by dtereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler2(int signum, t_stack *stack1, int client_pid)
{
	stack1->cur_chr <<= 1;
	stack1->bit_count++;
	if (signum == SIGUSR2)
		stack1->cur_chr |= 1;
	usleep(100);
	kill(client_pid, SIGUSR2);
	if (stack1->bit_count == 8)
	{
		stack1->message[stack1->index++] = stack1->cur_chr;
		if (stack1->cur_chr == '\0')
		{
			ft_printf("\nMessage from the client: %s\n", stack1->message);
			free(stack1->message);
			stack1->message = NULL;
			stack1->index = 0;
		}
		stack1->bit_count = 0;
		stack1->cur_chr = 0;
	}
}

void	handler1(int signum, siginfo_t *info, void *context)
{
	static t_stack	stack1 = {0};
	int				client_pid;

	(void)context;
	if (!stack1.message)
	{
		stack1.message = malloc(5120 * sizeof(char));
		if (!stack1.message)
			exit(EXIT_FAILURE);
		stack1.bit_count = 0;
		stack1.cur_chr = 0;
		stack1.index = 0;
	}
	client_pid = info->si_pid;
	handler2(signum, &stack1, client_pid);
}

int	main(void)
{
	struct sigaction	st;

	ft_memset(&st, 0, sizeof(st));
	st.sa_sigaction = handler1;
	st.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &st, NULL);
	sigaction(SIGUSR2, &st, NULL);
	ft_printf("The PID number of the server: %d\n", getpid());
	while (42)
		pause();
	return (0);
}
