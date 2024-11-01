/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:22:50 by npolack           #+#    #+#             */
/*   Updated: 2024/10/29 19:42:12 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

////////////////////////// CLIENT //////////////////////////////////////////////

void	send_to(pid_t pid, char *message);
void	get_response(int sig, siginfo_t *info, void *context);

int	main(int argc, char **argv)
{
	char				*message;
	int					server_pid;
	struct sigaction	response;

	response.sa_sigaction = get_response;
	sigaction(SIGUSR1, &response, NULL);
	if (argc != 3)
		return (0);
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		return (0);
	message = 0;
	message = ft_strdup(argv[2]);
	if (!message)
		return (0);
	send_to(server_pid, message);
	return (0);
}

void	send_to(pid_t pid, char *message)
{
	unsigned char	c;
	int				i;

	while (*message)
	{
		c = *message;
		i = 7;
		while (i >= 0)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(100);
		}
		message++;
	}
	i = -1;
	while (++i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	get_response(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		ft_printf("message received from %i", info->si_pid);
}
