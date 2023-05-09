/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:20:36 by lvincent          #+#    #+#             */
/*   Updated: 2023/02/16 17:02:02 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_format(char c, va_list params)
{
	size_t	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar_fd(va_arg(params, int), 1);
	else if (c == 's')
		i += ft_putstr_fd(va_arg(params, char *), 1);
	else if (c == 'p')
		i += ft_ptr(va_arg(params, unsigned long long));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr_fd(va_arg(params, int), 1);
	else if (c == 'u')
		i += ft_putunbr_fd(va_arg(params, unsigned int), 1);
	else if (c == 'x' || c == 'X')
		i += ft_puthex(va_arg(params, unsigned int), c);
	else if (c == '%')
		i += write(1, "%", 1);
	else
	{
		i += write(1, "%", 1);
		i += write(1, &c, 1);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		print_len;
	va_list	params;

	i = 0;
	print_len = 0;
	va_start(params, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			print_len += ft_format(format[i + 1], params);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			print_len++;
		}
		i++;
	}
	return (print_len);
}
