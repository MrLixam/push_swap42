/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:45:48 by lvincent          #+#    #+#             */
/*   Updated: 2022/11/14 00:35:05 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(long long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long long	big;
	int			i;
	char		*rv;

	big = n;
	big = (big * ((big > 0) - (big < 0)));
	i = 0;
	if (n < 0)
		i = 1;
	rv = malloc(i + ft_nblen(big) + 1);
	if (!rv)
		return (rv);
	if (i == 1)
		rv[0] = '-';
	i = i + ft_nblen(big);
	rv[i] = '\0';
	while (big > 9)
	{
		rv[--i] = big % 10 + '0';
		big /= 10;
	}
	rv[--i] = big % 10 + '0';
	return (rv);
}
