/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:30:20 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/30 16:57:47 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrx(t_list **stack, int x)
{
	t_list *tmp;

	tmp = ft_lstlast(*stack);
	tmp->next = *stack;
	tmp = tmp->next;
	*stack = tmp->next;
	tmp->next = NULL;
	if (x == 1)
		ft_printf("rra\n");
	if (x == 2)
		ft_printf("rrb\n");
}


void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rrx(stack_a, 0);
	ft_rrx(stack_b, 0);
	ft_printf("rrr\n");
}

int	check_sort(t_list **stack, int max)
{
	t_list *head;
	t_content *current;	
	int	last;

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
	t_list *tmp;
	t_content *content;

	tmp = *stack;
	while (index--)
		tmp = tmp->next;
	content = tmp->content;
	return (content->v_index);
}

size_t	find_min(t_list **stack)
{
	size_t	min;
	t_list	*head;
	size_t	i;

	head = *stack;
	min = 0;
	i = 0;
	while (head != NULL)
	{
		if (read_value(stack, min) > read_value(stack, i))
			min = i;
		i++;
		head = head->next;
	}
	return (min);
}