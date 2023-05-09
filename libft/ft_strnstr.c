/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 00:58:32 by lvincent          #+#    #+#             */
/*   Updated: 2022/11/11 15:06:58 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;

	if ((big == NULL || little == NULL) && len == 0)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (*big && i + ft_strlen(little) <= len)
	{
		if (!ft_strncmp(big, little, ft_strlen(little)))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
