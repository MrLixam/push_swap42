/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:15:15 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/27 18:26:51 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error!\n", 8);
	exit(EXIT_FAILURE);
}

static char *add_arg(char *s1, char *s2)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(s2, s1);
	if (!tmp)
		return (NULL);
	tmp2 = ft_strjoin(tmp, " ");
	free(tmp);
	if (!tmp2)
		return (NULL);
	tmp = tmp2;
	return (tmp);
}

void	check_arr(char **arr)
{
	int	i;
	int	j;
	int	click;

	i = -1;
	while (arr[++i])
	{
		j = -1;
		click = 0;
		while (arr[i][++j])
		{
			if (ft_isdigit(arr[i][j]))
				click = 1;
			else if (click && !ft_isdigit(arr[i][j]))
			{
				ft_free_arr(arr);
				ft_error();
			}
			else if (arr[i][j] != '+' && arr[i][j] != '-')
			{
				ft_free_arr(arr);
				ft_error();
			}
		}
	}
}

static void	check_err(char **arr)
{
	if (!arr)
		ft_error();
	if (arr[0] == NULL)
	{
		ft_free_arr(arr);
		ft_error();
	}
}

char **parsing(char **argv, int argc)
{
	char **ret;
	char *tmp;
	char *str;
	int i;

	if (argc == 1)
		exit(EXIT_FAILURE);
	i = 0;
	str = ft_strdup("");
	while (++i < argc)
	{
		tmp = add_arg(argv[i], str);
		free(str);
		if (!tmp)
		{
			free(tmp);
			ft_error();
		}
		str = tmp;
	}
	ret = ft_split(str, ' ');
	free(str);
	check_err(ret);
	check_arr(ret);
	return (ret);
}