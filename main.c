/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:50:48 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/26 13:26:20 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
	t_list **stack;
	t_list **stack2;
	t_list *tmp;
	t_content	*temp;

	stack = malloc(sizeof(t_list **));
	stack2 = malloc(sizeof(t_list **));
	init_stack(stack, stack2, argv, argc);
	tmp = *stack;
	while (tmp != NULL)
	{
		temp = tmp->content;
		ft_printf("%d ", temp->v_index);
		tmp = tmp->next;
	}
	delete_stacks(stack, stack2);
}
