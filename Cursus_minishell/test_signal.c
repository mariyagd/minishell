#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("received SIGINT\n");
	}
	if (signo == SIGQUIT)
	{
		usleep (1500000);
		printf("received SIGQUIT\n");
	}
}

int main(int ac, char **av)
{
	(void)ac;
	
	if (av[1][0] == 'c')
		return (130);
	else 
		return (131);
}
