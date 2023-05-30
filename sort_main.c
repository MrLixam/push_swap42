/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:37:08 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/30 17:28:27 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_list **stack, int s)
{
	while(check_sort(stack, 3) == -1)
	{
		if (read_value(stack, 0) > read_value(stack, 1))
			ft_sx(stack, s);
		else
			ft_rx(stack, s);
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
		if(min > ft_lstsize(*stack_a) / 2)
		{
			while (min++ < ft_lstsize(*stack_a))
				ft_rx(stack_a, 1);
			ft_px(stack_b, stack_a, 2);
		}
		else
		{
			while (min--)
				ft_rrx(stack_a, 1);
			ft_px(stack_b, stack_a, 2);
		}
	}
	sort_3(stack_a, 1);
	print_lst(stack_a);
	print_lst(stack_b);
	if ((read_value(stack_b, 0) <  read_value(stack_b, 1)) && size == 5)
		ft_sx(stack_b, 2);
	print_lst(stack_a);
	print_lst(stack_b);
	ft_px(stack_a, stack_b, 1);
	print_lst(stack_a);
	print_lst(stack_b);
	if (size == 5)
		ft_px(stack_a, stack_b, 1);	
}

void	sort_main(t_list **stack_a, t_list **stack_b)
{
	int	i;

	if (!stack_b)
		ft_printf("yes");
	if (!check_sort(stack_a, ft_lstsize(*stack_a)))
		return ;
	i = ft_lstsize(*stack_a);
	if (i == 2)
		ft_rx(stack_a, 1);
	if (i == 3)
		sort_3(stack_a, 1);
	if (i == 4 || i == 5)
		sort_5(stack_a, stack_b);
	return ;
}