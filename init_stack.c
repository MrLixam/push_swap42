/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:01:51 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/31 10:55:45 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_content	*init_struct(int value)
{
	t_content	*cnt;

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

void	init_stack(t_list **stk_a, t_list **stk_b, char **foo, int nb)
{
	t_list		*tmp;
	int			i;

	*stk_b = NULL;
	i = 0;
	tmp = ft_lstnew(init_struct(ft_atoi(foo[i])));
	if (!tmp)
		return ;
	*stk_a = tmp;
	while (++i < nb)
	{
		tmp = ft_lstnew(init_struct(ft_atoi(foo[i])));
		if (!tmp)
			return ;
		ft_lstadd_back(stk_a, tmp);
	}
	init_v_index(stk_a);
}

void	delete_stacks(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
		ft_lstclear(stack_a, &del);
	if (*stack_b)
		ft_lstclear(stack_b, &del);
	free(stack_a);
	free(stack_b);
}
