#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "Libft/libft.h"

volatile sig_atomic_t g_ack = 0;

void ack_handler(int sig)
{
    if (sig == SIGUSR1)
    {
        g_ack = 1;
	}
    if (sig == SIGUSR2)
        write(1, "Message recieved!\n", 19);
}
void send_signal(int pid, unsigned char c)
{
    int i = 0;
    while(i < 8)
    {
        if(c >> (7 - i) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        if (g_ack == 0)
            usleep(100);
        g_ack = 0;
        i++;
    }
}
void client(int pid, char *str)
{
    int i = 0;
    while(str[i])
    {
        send_signal(pid, str[i]);
        i++;
    }
    send_signal(pid, '\0');
}
int main(int ac ,char **av)
{
    int i = 0;
    if(ac != 3)
        return(write(2, "Error\n", 6));
    while(av[1][i])
    {
        if(!ft_isdigit(av[1][i]))
            return(write(2, "INVALID PID\n", 13));
        i++;
    }
    int pid = ft_atoi(av[1]);
    struct sigaction sa;
    sa.sa_handler = &ack_handler;
	sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    client(pid, av[2]);
}


