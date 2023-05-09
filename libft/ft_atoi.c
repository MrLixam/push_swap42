/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:43:58 by lvincent          #+#    #+#             */
/*   Updated: 2022/11/14 00:37:10 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				ints[2];
	unsigned int	res;

	ints[0] = 0;
	res = 0;
	ints[1] = 1;
	while ((nptr[ints[0]] >= 9 && nptr[ints[0]] <= 13) || nptr[ints[0]] == ' ')
		ints[0]++;
	if (nptr[ints[0]] == '-' || nptr[ints[0]] == '+')
		if (nptr[ints[0]++] == '-')
			ints[1] = -1;
	while (nptr[ints[0]] && ft_isdigit(nptr[ints[0]]))
	{
		if ((res * 10) + (nptr[ints[0]] - '0') < res && ints[1] == 1)
			return (-1);
		else if ((res * 10) + (nptr[ints[0]] - '0') < res && ints[1] == -1)
			return (0);
		res = (res * 10) + (nptr[ints[0]] - '0');
		ints[0]++;
	}
	return (ints[1] * res);
}
