/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:30:20 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/09 17:55:59 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rx(int *stack)
{
	int tmp;
	int i;

	tmp = stack[0];
	i = 0;
	while (stack[++i])
		stack[i - 1] = stack[i];
	stack[i - 1] = tmp; 
}

void	ft_rr(int *stack_a, int *stack_b)
{
	ft_rx(stack_a);
	ft_rx(stack_b);
}

//void ft_rrx()

//void ft_rrr()