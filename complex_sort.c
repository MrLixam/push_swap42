/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:47:11 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/31 18:05:14 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_back(t_list **sa, t_list **sb)
{
	size_t	index;
	size_t	tmp;
	size_t	med;

	while (*sb != NULL)
	{
		med = ft_lstsize(*sb) / 2;
		index = find_max(sb);
		tmp = read_value(sb, (int)index);
		while (read_value(sb, 0) != tmp)
		{
			if (index > med)
				ft_rrx(sb, 2);
			else
				ft_rx(sb, 2);
		}
		ft_px(sa, sb, 1);
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
