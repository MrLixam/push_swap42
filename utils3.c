/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:22:04 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/31 05:51:09 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_list **stack)
{
	t_list *head;
	t_content *content;

	head = *stack;
	ft_printf("start of list\n");
	while (head != NULL)
	{
		content = head->content;
		ft_printf("%d\n", content->value);
		head = head->next;
	}
	ft_printf("end of list\n\n");
}

size_t	find_max(t_list **stack)
{
	size_t	max;
	t_list	*head;
	size_t	i;

	head = *stack;
	max = 0;
	i = 0;
	while (head != NULL)
	{
		if (read_value(stack, max) < read_value(stack, i))
			max = i;
		i++;
		head = head->next;
	}
	return (max);
}
