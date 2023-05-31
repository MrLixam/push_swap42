/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:37:08 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/31 10:03:06 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_list **stack, int s)
{
	while (check_sort(stack, 3) == -1)
	{	
		if (read_value(stack, 0) > read_value(stack, 1))
		{
			if (read_value(stack, 0) > read_value(stack, 2))
			{
				ft_rx(stack, 1);
				continue ;
			}	
		}		
		if (read_value(stack, 0) > read_value(stack, 1))
			ft_sx(stack, s);
		else
			ft_rrx(stack, s);
	}
}

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	size_t	min;
	size_t	size;

	size = ft_lstsize(*stack_a);
	while (ft_lstsize(*stack_a) != 3)
	{
		min = find_min(stack_a);
		if (min > ft_lstsize(*stack_a) / 2)
			while (min++ < ft_lstsize(*stack_a))
				ft_rrx(stack_a, 1);
		else
			while (min--)
				ft_rx(stack_a, 1);
		ft_px(stack_b, stack_a, 2);
	}
	sort_3(stack_a, 1);
	ft_px(stack_a, stack_b, 1);
	if (size == 5)
		ft_px(stack_a, stack_b, 1);
}

void	sort_main(t_list **stack_a, t_list **stack_b)
{
	int	i;

	if (!check_sort(stack_a, ft_lstsize(*stack_a)))
		return ;
	i = ft_lstsize(*stack_a);
	if (i == 2)
		ft_rx(stack_a, 1);
	if (i == 3)
		sort_3(stack_a, 1);
	if (i == 4 || i == 5)
		sort_5(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b);
	return ;
}
