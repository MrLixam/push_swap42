/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:30:20 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/27 23:27:12 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrx(t_list **stack, int x)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = ft_lstlast(*stack);
	tmp2 = *stack;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	ft_lstadd_front(stack, tmp);
	tmp2->next = NULL;
	if (x == 1)
		ft_printf("rra");
	if (x == 2)
		ft_printf("rrb");
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rrx(stack_a, 0);
	ft_rrx(stack_b, 0);
}

int	check_sort(t_list **stack, int max)
{
	t_list *head;
	t_content *current;	
	int	last;

	head = *stack;
	current = head->content;
	last = current->value;
	while (head != NULL || max-- != 0)
	{
		current = head->content;
		if (last > current->value)
			return (-1);
		last = current->value;
		head = head->next;
	}
	return (0);
}

int read_value(t_list **stack, int	index)
{
	t_list *tmp;
	t_content *content;

	tmp = *stack;
	while (index)
}