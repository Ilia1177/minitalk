#include "minitalk.h"

void	print_message(int sig)
{
	ft_printf("message received\n");
//	exit(0);
}

// SERVER
int main(void)
{
	pid_t		pid;
	sigset_t	signals;
//	struct sigaction action;

	pid = getpid();
//	action.sa_handler = print_message;
//	sigemptyset(&action.sa_mask);
//	action.sa_flags = 0;
//	sigemptyset(&signals);
//	sigaddset(&signals, SIGUSR1);
	ft_printf("%d\n", pid);
	signal(SIGUSR1, print_message);
	signal(SIGUSR2, print_message);
	while(1)
	{
		ft_printf("listening...\n");
		sleep(10);
	}
	return (0);
}


