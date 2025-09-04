#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	signal_handler(int signum, siginfo_t *info, void *context)
{
    static int i;
    static char c;
    (void)context;
    if(signum == SIGUSR2)
        c |= (1 << (7 - i));
    i++;
    if(i == 8)
    {
        if(c == '\0')
        {
            write(1, "\n", 1);
            kill(info->si_pid, SIGUSR2);
        }
        else
            write(1, &c, 1);
        i = 0;
        c = 0;
    }
    kill(info->si_pid, SIGUSR1);
}
// int	main(void)
// {
// 	int pid;
// 	pid = getpid();
// 	printf("%d\n", pid);
// 	signal(SIGUSR1, signal_handler);
// 	signal(SIGUSR2, signal_handler);
// 	while (1)
// 	{
// 		pause();
// 	}
// }

int main(void)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handler;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    printf("%d\n", getpid());
    while(1)
    {
        pause();
    }
}