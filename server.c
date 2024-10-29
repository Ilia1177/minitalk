/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:05:34 by npolack           #+#    #+#             */
/*   Updated: 2024/10/29 19:41:25 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

////////////////////////// SERVER //////////////////////////////////////////////

void	handle_sigusr(int sig, siginfo_t *info, void *context);
void	send_confirmation(pid_t pid);

int	main(void)
{
	struct sigaction	action;

	sigemptyset(&action.sa_mask);
	action.sa_sigaction = handle_sigusr;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
	{
		ft_printf("sigaction for SIGUSR1 failed");
		exit(1);
	}
	if (sigaction(SIGUSR2, &action, NULL) == -1)
	{
		ft_printf("sigaction for SIGUSR2 failed");
		exit(1);
	}
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}

void	handle_sigusr(int sig, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static sig_atomic_t		bits_count;

	(void)context;
	if (sig == SIGUSR1)
		current_char = current_char | (1 << (7 - bits_count));
	bits_count++;
	if (bits_count == 8)
	{
		if (current_char == 0)
			send_confirmation(info->si_pid);
		else
			ft_printf("%c", current_char);
		bits_count = 0;
		current_char = 0;
	}
}

void	send_confirmation(pid_t pid)
{
	kill(pid, SIGUSR1);
	ft_printf("\n");
}
