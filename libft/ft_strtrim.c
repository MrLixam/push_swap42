/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:14:48 by lvincent          #+#    #+#             */
/*   Updated: 2022/11/12 18:44:39 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

static long long	ft_trim_st(char *str, char *set)
{
	size_t	rv;
	size_t	i;

	i = 0;
	rv = 0;
	while (str[i])
	{
		if (!ft_inset(str[i++], set))
			break ;
		else
			rv++;
	}
	return (rv);
}

static long long	ft_trim_nd(char *str, char *set)
{
	long long	rv;
	long long	i;

	i = ft_strlen((const char *)str) - 1;
	rv = i;
	while (i > 0)
	{
		if (!ft_inset(str[i--], set))
			break ;
		else
			rv--;
	}
	return (rv);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	long long	start;
	long long	end;
	char		*rv;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_trim_st((char *)s1, (char *)set);
	end = ft_trim_nd((char *)s1, (char *)set);
	if (start > end)
		return (ft_strdup(""));
	rv = ft_substr(s1, start, end - start + 1);
	if (!rv)
		return (NULL);
	else
		return (rv);
}
