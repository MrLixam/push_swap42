/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:22:04 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/30 17:29:26 by lvincent         ###   ########.fr       */
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