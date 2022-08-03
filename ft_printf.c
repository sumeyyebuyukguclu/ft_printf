/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbuyukgu <sbuyukgu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:01:45 by sbuyukgu          #+#    #+#             */
/*   Updated: 2022/07/08 12:10:28 by sbuyukgu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_control(char c, va_list arg)
{
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 'd' || c == 'i')
		return (ft_abs(va_arg(arg, int)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_convert(
				va_arg(arg, unsigned long), "0123456789abcdef") + 2);
	}
	else if (c == 'u')
		return (ft_convert(va_arg(arg, unsigned int), "0123456789"));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'x')
		return (ft_convert(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_convert(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		j;

	va_start(arg, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
			{
				j += ft_type_control(str[i + 1], arg);
				i++;
			}
		}
		else
			j += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (j);
}
