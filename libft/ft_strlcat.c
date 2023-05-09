/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:53:52 by lvincent          #+#    #+#             */
/*   Updated: 2022/11/14 03:03:58 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	dest_i;

	if (size == 0)
		return (ft_strlen(src));
	dest_i = 0;
	while (dest[dest_i] && dest_i < size)
		dest_i++;
	i = 0;
	while (src[i] && dest_i + i < size - 1)
	{
		dest[dest_i + i] = src[i];
		i++;
	}
	if (dest_i < size)
		dest[dest_i + i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (dest_i + i);
}
