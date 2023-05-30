/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:11:08 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/30 18:28:28 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sx(t_list **stack, int x)
{
	t_list		*first;
	t_list		*i;
	t_content	*tmp;

	first = *stack;
	i = first->next;
	tmp = first->content;
	first->content = i->content;
	i->content = tmp;
	if (x == 1)
		ft_printf("sa\n");
	if (x == 2)
		ft_printf("sb\n");
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_sx(stack_a, 0);
	ft_sx(stack_b, 0);
	ft_printf("ss\n");
}

void	del(void *to_del)
{
	free(to_del);
}

void	ft_px(t_list **stack_to, t_list **stack_from, int x)
{
	t_list		*new;
	t_list		*tmp;
	size_t		size;
	t_content	*temp;
	t_content	*new_cnt;
	
	if (!*stack_from)
		return ;
	tmp = *stack_from;
	temp = tmp ->content;
	new_cnt = init_struct(temp->value);
	new_cnt->v_index = temp->v_index;
	new = ft_lstnew(new_cnt);
	ft_lstadd_front(stack_to, new);
	*stack_from = tmp->next;
	size = ft_lstsize(*stack_from);
	ft_lstdelone(tmp, &del);
	tmp->content = NULL;
	if (!(size - 1))
		*stack_from = NULL;
	if (x == 1)
		ft_printf("pa\n");
	if (x == 2)
		ft_printf("pb\n");
}

void	ft_rx(t_list **stack, int x)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = ft_lstlast(*stack);
	tmp2 = *stack;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp->next = *stack;
	tmp2->next = NULL;
	*stack = tmp;
	if (x == 1)
		ft_printf("ra\n");
	if (x == 2)
		ft_printf("rb\n");
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	ft_rx(stack_a, 0);
	ft_rx(stack_b, 0);
	ft_printf("rr\n");
}