#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "ft_printf/ft_printf.h"

int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
void	signal_handler(int signum, siginfo_t *info, void *context);
void ack_handler(int sig);
void send_signal(int pid, unsigned char c);
void client(int pid, char *str);

#endif