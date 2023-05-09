/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:11:08 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/09 17:59:32 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_lst_len(int *lst)
{
	int	i;

	i = -1;
	while (lst[++i])
		if (lst[i] == NULL)
			return (i);
}

void	ft_sx(int *stack)
{
	int tmp;
	
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	ft_ss(int *stack_a, int *stack_b)
{
	ft_sx(stack_a);
	ft_sx(stack_b);
}

void	ft_pa(int *stack_a, int *stack_b)
{
	int *new_a;
	int *new_b;
	int i;

	new_a = ft_calloc(ft_lst_len(stack_a) + 1, sizeof(int));
	new_a[0] = stack_b[0];
	i = -1;
	while (stack_a[++i])
		new_a[i + 1] = stack_a[i];
	free(stack_a);
	stack_a = new_a;
	new_b = ft_calloc(ft_lst_len(stack_b) - 1, sizeof(int));
	i = -1;
	while (stack_b[++i + 1])
		new_b[i] = stack_b[i + 1];
	free(stack_b);
	stack_b = new_b;
}

void	ft_pb(int *stack_a, int *stack_b)
{
	int *new_a;
	int *new_b;
	int i;

	new_b = ft_calloc(ft_lst_len(stack_b) + 1, sizeof(int));
	new_b[0] = stack_a[0];
	i = -1;
	while (stack_b[++i])
		new_b[i + 1] = stack_b[i];
	free(stack_b);
	stack_b = new_b;
	new_a = ft_calloc(ft_lst_len(stack_a) - 1, sizeof(int));
	i = -1;
	while (stack_a[++i + 1])
		new_a[i] = stack_a[i + 1];
	free(stack_a);
	stack_a = new_a;
}