/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:47:17 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/14 18:47:18 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'c')
		len += ft_putchar((char)va_arg(args, int));
	else if (format == '%')
		len += ft_putchar('%');
	else if (format == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (format == 'x')
		len += ft_puthex(va_arg(args, unsigned int));
	else if (format == 'X')
		len += ft_putheX(va_arg(args, unsigned int));
	else if (format == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
