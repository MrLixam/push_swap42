/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:01:51 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/22 18:50:37 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_content	*init_struct(int value)
{
	t_content *cnt;

	cnt = malloc(sizeof(t_content));
	cnt->v_index = NULL;
	cnt->value = value;
	return (cnt);
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
	init_v_index(stack_a, arc - 1);
}

void	init_v_index(t_list **stack_a, int nb_n)
{
	t_list	*tmp;
	int		i
	int		sort;
	int		min[2];

	sort = 0;
	min[0] = tmp->content->value;
	while (sort <= nb_n)
	{
		i = 0;
				
	}
}