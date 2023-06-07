/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:30:20 by lvincent          #+#    #+#             */
/*   Updated: 2023/06/07 19:09:51 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rrx(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = ft_lstlast(*stack);
		tmp2 = *stack;
		while (tmp2->next != tmp)
			tmp2 = tmp2->next;
		tmp->next = *stack;
		tmp2->next = NULL;
		*stack = tmp;
	}
}

void	ft_px(t_list **stack_to, t_list **stack_from)
{
	t_list		*new;
	t_list		*tmp;
	t_content	*temp;
	t_content	*new_cnt;

	if (*stack_from)
	{
		tmp = *stack_from;
		temp = tmp ->content;
		new_cnt = init_struct(temp->value);
		new_cnt->v_index = temp->v_index;
		new = ft_lstnew(new_cnt);
		ft_lstadd_front(stack_to, new);
		*stack_from = tmp->next;
		ft_lstdelone(tmp, &del);
	}
}

int	check_sort(t_list **stack, int max)
{
	t_list		*head;
	t_content	*current;	
	int			last;

	head = *stack;
	current = head->content;
	last = current->value;
	while (head != NULL && max-- != 0)
	{
		current = head->content;
		if (last > current->value)
			return (-1);
		last = current->value;
		head = head->next;
	}
	return (0);
}

size_t	read_value(t_list **stack, int index)
{
	t_list		*tmp;
	t_content	*content;

	tmp = *stack;
	while (index--)
		tmp = tmp->next;
	content = tmp->content;
	return (content->v_index);
}
