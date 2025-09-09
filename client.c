#include "minitalk.h"

volatile sig_atomic_t g_ack = 0;

void ack_handler(int sig)
{
    (void)sig;
    g_ack = 1;
}
void send_signal(int pid, unsigned char c)
{
    int i = 0;
    while(i < 8)
    {
        g_ack = 0;
        if(c >> (7 - i) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(300);
        while(!g_ack)
            pause();
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
    signal(SIGUSR1, ack_handler);
    client(pid, av[2]);
}