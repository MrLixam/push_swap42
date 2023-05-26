/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:01:51 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/26 12:59:54 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_content	*init_struct(int value)
{
	t_content *cnt;

	cnt = malloc(sizeof(t_content *));
	cnt->v_index = -1;
	cnt->value = value;
	return (cnt);
}

static void	init_v_index(t_list **stack_a)
{
	t_list	*current;
	t_list	*tmp;
	int		c_value;
	int		diff;

	current = *stack_a;
	while (current != NULL)
	{
		diff = 0;
		c_value = ((t_content *)current->content)->value;
		tmp = *stack_a;
		while (tmp != NULL)
		{
			if (c_value > ((t_content *)tmp->content)->value)
				diff++;
			tmp = tmp->next;
		}
		((t_content *)current->content)->v_index = diff;
		current = current->next;
	}
}

void	init_stack(t_list **stack_a, t_list **stack_b, char **argv, int argc)
{
	t_list		*tmp;
	int			i;

	tmp = ft_lstnew(NULL);
	if (!tmp)
		return ;
	*stack_b = tmp;
	i = 1;
	tmp = ft_lstnew(init_struct(ft_atoi(argv[i])));
	if (!tmp)
		return ;
	*stack_a = tmp;
	while (++i < argc)
	{
		tmp = ft_lstnew(init_struct(ft_atoi(argv[i])));
		if (!tmp)
			return ;
		ft_lstadd_back(stack_a, tmp);
	}
	init_v_index(stack_a);
}

void	delete_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, &del);
	ft_lstclear(stack_b, &del);
	free(stack_a);
	free(stack_b);
}