/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:11:08 by lvincent          #+#    #+#             */
/*   Updated: 2023/06/01 09:31:22 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sx(t_list **stack, int x)
{
	t_list		*first;
	t_list		*i;
	t_content	*tmp;

	first = *stack;
	i = first->next;
	tmp = first->content;
	first->content = i->content;
	i->content = tmp;
	if (x == 1)
		ft_printf("sa\n");
	if (x == 2)
		ft_printf("sb\n");
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sx(stack_a, 0);
	ft_sx(stack_b, 0);
	ft_printf("ss\n");
}

void	del(void *to_del)
{
	free(to_del);
}

void	ft_rx(t_list **stack, int x)
{
	t_list	*tmp;

	tmp = ft_lstlast(*stack);
	tmp->next = *stack;
	tmp = tmp->next;
	*stack = tmp->next;
	tmp->next = NULL;
	if (x == 1)
		ft_printf("ra\n");
	if (x == 2)
		ft_printf("rb\n");
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rx(stack_a, 0);
	ft_rx(stack_b, 0);
	ft_printf("rr\n");
}
