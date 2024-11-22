/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npolack <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:05:34 by npolack           #+#    #+#             */
/*   Updated: 2024/11/22 11:36:26 by npolack          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////////////// SERVER //////////////////////////////////////////////

#include "minitalk.h"

static char	*ft_charjoin(const char *str, unsigned char current_char);
static char	*send_confirmation(pid_t pid, char *str);
static void	handle_sigusr(int sig, siginfo_t *info, void *context);
static void	free_and_exit(void *str);

int	main(void)
{
	struct sigaction	action;

	sigemptyset(&action.sa_mask);
	action.sa_sigaction = handle_sigusr;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGINT, &action, NULL) == -1)
	{
		ft_printf("sigaction for SIGINT failed");
		exit(1);
	}
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

void	free_and_exit(void *str)
{
	free(str);
	exit(0);
}

void	handle_sigusr(int sig, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static sig_atomic_t		bits_count;
	static char				*str;
	char					*tmp;

	(void)context;
	if (sig == SIGINT)
		free_and_exit(str);
	if (sig == SIGUSR1)
		current_char = current_char | (1 << (7 - bits_count));
	bits_count++;
	if (bits_count == 8)
	{
		if (current_char == 0)
			str = send_confirmation(info->si_pid, str);
		else
		{
			tmp = str;
			str = ft_charjoin(str, current_char);
			free(tmp);
		}
		bits_count = 0;
		current_char = 0;
	}
}

char	*ft_charjoin(const char *str, unsigned char current_char)
{
	char	*dest;
	int		i;

	if (!str)
	{
		dest = malloc(sizeof(char) * 2);
		dest[0] = current_char;
		dest[1] = '\0';
	}
	else
	{
		dest = malloc(sizeof (char) * (ft_strlen(str) + 2));
		i = 0;
		while (str[i])
		{
			dest[i] = str[i];
			i++;
		}
		dest[i] = current_char;
		dest[++i] = '\0';
	}
	return (dest);
}

char	*send_confirmation(pid_t pid, char *str)
{
	ft_printf("%s\n", str);
	free(str);
	kill(pid, SIGUSR1);
	return (NULL);
}
