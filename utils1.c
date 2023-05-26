/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:11:08 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/26 12:57:44 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sx(t_list **stack)
{
	t_list		*first;
	t_list		*i;
	t_content	*tmp;

	first = *stack;
	i = first->next;
	tmp = first->content;
	first->content = i->content;
	i->content = tmp;
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sx(stack_a);
	ft_sx(stack_b);
}

void	del(void *to_del)
{
	free(to_del);
}

void	ft_px(t_list **stack_to, t_list **stack_from)
{
	t_list	*new;
	t_list	*tmp;

	tmp = *stack_from;
	new = ft_lstnew(tmp->content);
	ft_lstadd_front(stack_to, new);
	*stack_from = tmp->next;
	ft_lstdelone(tmp, &del);
}

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