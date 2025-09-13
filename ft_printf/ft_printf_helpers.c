/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:47:21 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/14 18:47:22 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
int	ft_putnbr(int num)
{
	int		len;
	char	*n;

	n = ft_itoa(num);
	len = ft_putstr(n);
	free(n);
	return (len);
}
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
int	ft_putunsigned(unsigned int n)
{
	int len = 0;
	if (n >= 10)
		len += ft_putunsigned(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}