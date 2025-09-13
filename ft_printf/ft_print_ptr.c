/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:47:23 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/14 18:47:24 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_hex(uintptr_t num)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = 0;
	if (num >= 16)
		len += ft_putptr_hex(num / 16);
	len += ft_putchar(hex[num % 16]);
	return (len);
}
int	ft_putptr(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		len += ft_putstr("(nil)");
	else
	{
		len += ft_putstr("0x");
		len += ft_putptr_hex((uintptr_t)ptr);
	}
	return (len);
}
