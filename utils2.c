/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:30:20 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/27 17:22:38 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
