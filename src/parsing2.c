/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:18:50 by lvincent          #+#    #+#             */
/*   Updated: 2023/06/05 23:03:41 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dupe(char **arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[++j])
		{
			if (i != j)
			{
				if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				{
					ft_free_arr(arr);
					ft_error();
				}
			}
		}
	}
}

static int	check_int(char *to_check)
{
	char	*s1;
	char	*s2;
	int		i;

	s1 = ft_strtrim(to_check, "+-");
	if (!ft_strncmp(s1, "0", 1))
		return (0);
	s2 = ft_strjoin("-", s1);
	free(s1);
	s1 = s2;
	s2 = ft_itoa(ft_atoi(s1));
	i = ft_strncmp(s1, s2, ft_strlen(s1));
	free(s1);
	free(s2);
	if (i)
		return (1);
	return (0);
}

void	parsing2(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		if (check_int(arr[i]))
		{
			ft_free_arr(arr);
			ft_error();
		}
	}
	check_dupe(arr);
}
