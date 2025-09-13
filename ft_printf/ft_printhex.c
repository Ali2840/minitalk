/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:47:12 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/14 18:47:13 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_base(unsigned int num, char *base)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_puthex_base(num / 16, base);
	len += ft_putchar(base[num % 16]);
	return (len);
}

int	ft_puthex(unsigned int num)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	len += ft_puthex_base(num, base);
	return (len);
}
int	ft_putheX(unsigned int num)
{
	int len = 0;
	char *base = "0123456789ABCDEF";
	len += ft_puthex_base(num, base);
	return (len);
}