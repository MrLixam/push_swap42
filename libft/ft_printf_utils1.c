/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:14:20 by lvincent          #+#    #+#             */
/*   Updated: 2023/02/22 10:58:44 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_puthex(unsigned int nbr, char mode)
{
	unsigned long long	lnbr;
	char				*base;
	size_t				i;

	i = 0;
	if (mode == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	lnbr = nbr;
	if (lnbr < 16)
	{
		i += ft_putchar_fd(base[lnbr], 1);
		return (i);
	}
	else
	{	
		i += ft_puthex(lnbr / 16, mode);
		i += ft_puthex(lnbr % 16, mode);
	}
	return (i);
}

size_t	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned long	big;
	size_t			i;

	big = n;
	i = 0;
	if (big <= 9)
	{
		ft_putchar_fd('0' + big, fd);
		return (1);
	}
	else
	{
		i += ft_putunbr_fd(big / 10, fd);
		i += ft_putchar_fd('0' + big % 10, fd);
	}
	return (i);
}

size_t	ft_putptr(unsigned long long nbr)
{
	char	*base;
	size_t	i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr < 16)
	{
		i += ft_putchar_fd(base[nbr], 1);
		return (i);
	}
	else
	{	
		i += ft_putptr(nbr / 16);
		i += ft_putptr(nbr % 16);
	}
	return (i);
}

size_t	ft_ptr(unsigned long long ptr)
{
	size_t	i;

	i = 0;
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	i += write(1, "0x", 2);
	i += ft_putptr(ptr);
	return (i);
}
