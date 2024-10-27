#include "minitalk.h"
 //	CLIENT
void	send_to(pid_t pid, char *message);
int main(int argc, char **argv)
{
	(void)argc;

	char	*message;
	int		serverPID;
	int messagenum = 0x54;

	serverPID = ft_atoi(argv[1]);
	message = ft_strdup(argv[2]);
	send_to(serverPID, message);
	kill(serverPID, SIGUSR1);
}

void	send_to(pid_t pid, char *message)
{
	unsigned char	c;
	int				i;

	i = 0;
	while (*message)
	{
		c = *message;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		message++;
	}
	while (i < 7)
	{
		kill(pid, SIGUSR2);
		i++;
	}
	free(message);
}

