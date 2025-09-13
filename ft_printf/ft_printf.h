/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:47:15 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/14 18:47:16 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_putnbr(int num);
int	ft_putchar(char c);
int	ft_putptr_hex(uintptr_t num);
int	ft_putptr(void *ptr);
int	ft_putheX(unsigned int num);
int	ft_puthex(unsigned int num);
int	ft_putunsigned(unsigned int n);
char	*ft_itoa(int n);

#endif
