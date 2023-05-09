/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 00:12:05 by lvincent          #+#    #+#             */
/*   Updated: 2022/11/14 00:42:35 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmps1;
	unsigned char	*tmps2;

	tmps1 = (unsigned char *)s1;
	tmps2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*tmps1 != *tmps2)
			return (*tmps1 - *tmps2);
		tmps1++;
		tmps2++;
	}
	return (0);
}
