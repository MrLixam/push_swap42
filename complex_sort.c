/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:47:11 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/31 18:40:05 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_back(t_list **sa, t_list **sb)
{
	size_t	nb[3];

	while (*sb != NULL)
	{
		nb[2] = 0;
		nb[0] = find_max(sb);
		nb[1] = read_value(sb, (int)nb[0]);
		while (read_value(sb, 0) != nb[1])
		{
			if (read_value(sb, 0) == nb[1] - 1)
			{
				ft_px(sa, sb, 1);
				nb[0] = find_max(sb);
				nb[2]++;
				continue ;
			}
			if (nb[0] >= ft_lstsize(*sb) / 2)
				ft_rrx(sb, 2);
			else if (nb[0] < ft_lstsize(*sb) / 2)
				ft_rx(sb, 2);
		}
		ft_px(sa, sb, 1);
		if (nb[2])
			ft_sx(sa, 1);
	}
}

static void	send(t_list **sa, t_list **sb, size_t start, size_t end)
{
	size_t	med;
	size_t	size;

	size = ft_lstsize(*sa);
	med = (start + end) / 2;
	while (size--)
	{
		if ((read_value(sa, 0) >= start) && (read_value(sa, 0) < end))
		{	
			ft_px(sb, sa, 2);
			if (read_value(sb, 0) >= med)
				ft_rx(sb, 2);
		}
		else
			ft_rx(sa, 1);
	}
}

static void	butterfly(t_list **sa, t_list **sb, int x)
{
	int	i;
	int	j;

	j = 0;
	i = ft_lstsize(*sa) / x;
	while (j <= x)
	{
		send(sa, sb, j * i, (j + 1) * i);
		j++;
	}
	send_back(sa, sb);
}

void	complex_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 500)
		butterfly(stack_a, stack_b, 5);
	else
		butterfly(stack_a, stack_b, 10);
}
