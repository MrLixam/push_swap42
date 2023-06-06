/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:11:08 by lvincent          #+#    #+#             */
/*   Updated: 2023/06/06 00:00:50 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	del(void *to_del)
{
	free(to_del);
}

void	ft_rx(t_list **stack)
{
	t_list	*tmp;

	tmp = ft_lstlast(*stack);
	tmp->next = *stack;
	tmp = tmp->next;
	*stack = tmp->next;
	tmp->next = NULL;
}
