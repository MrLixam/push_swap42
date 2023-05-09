/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:30:20 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/09 18:57:29 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rx(t_list **stack)
{
	t_list *tmp;

	tmp = ft_lstlast(*stack);
	tmp->next = *stack;
	tmp = tmp->next;
	*stack = tmp->next;
	tmp->next = NULL;
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rx(stack_a);
	ft_rx(stack_b);
}

void	ft_rrx(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = ft_lstlast(*stack);
	tmp2 = *stack;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	ft_lstadd_front(stack, tmp);
	tmp2->next = NULL;
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rrx(stack_a);
	ft_rrx(stack_b);
}