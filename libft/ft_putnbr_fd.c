/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:15:28 by lvincent          #+#    #+#             */
/*   Updated: 2023/02/22 10:57:32 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	long long	big;
	size_t		i;

	big = n;
	i = 0;
	if (big < 0)
	{
		i += ft_putchar_fd('-', fd);
		big = big * -1;
	}
	if (big <= 9)
	{
		i += ft_putchar_fd('0' + big, fd);
		return (i);
	}
	else
	{
		i += ft_putnbr_fd(big / 10, fd);
		i += ft_putchar_fd('0' + big % 10, fd);
	}
	return (i);
}
