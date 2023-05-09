/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:19:12 by lvincent          #+#    #+#             */
/*   Updated: 2022/11/11 15:04:56 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*rv;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen((const char *)s) < start)
		return (ft_strdup(""));
	if (ft_strlen((const char *)s) >= (start + len))
		rv = malloc(len + 1);
	else
		rv = malloc(1 + len - ((start + len) - ft_strlen((const char *)s)));
	if (!rv)
		return (NULL);
	i = 0;
	while ((i < len) && s[start + i])
	{
		rv[i] = s[start + i];
		i++;
	}
	rv[i] = '\0';
	return (rv);
}
