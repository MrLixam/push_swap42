/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:01:51 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/09 19:13:21 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	init_stack(t_list **stack_a, t_list **stack_b, char **argv, int argc)
{
	t_list	*tmp;
	int		i;

	tmp = ft_lstnew(NULL);
	if (tmp = NULL)
	*stack_b = tmp;
	i = 0;
	tmp =ft_lstnew(argv[0]);
	*stack_a = tmp;
	while (++i < argc)
		ft_lstadd_back(stack_a, ft_lstnew(argv[i]));
}