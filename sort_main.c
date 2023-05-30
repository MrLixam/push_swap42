/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:37:08 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/30 06:34:59 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_list **stack)
{
	ft_printf("%d", read_value(stack, 2));
}

void sort_main(t_list **stack_a, t_list **stack_b)
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
		sort_3(stack_a);

	return ;
}