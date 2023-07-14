/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:18:50 by lvincent          #+#    #+#             */
/*   Updated: 2023/07/14 17:21:10 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_dupe(char **arr)
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
	int	error;

	error = 0;
	ft_atoi_err(to_check, &error);
	return (error);
}

static int	not_digit(char *to_check)
{
	char	*s1;

	s1 = ft_strtrim(to_check, "+- ");
	if (!ft_strlen(s1))
	{
		free(s1);
		return (1);
	}
	free(s1);
	return (0);
}

void	parsing2(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		if (check_int(arr[i]) || not_digit(arr[i]))
		{
			ft_free_arr(arr);
			ft_error();
		}
	}
	check_dupe(arr);
}
