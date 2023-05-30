/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:50:48 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/30 06:34:11 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
	char		**foo;
	t_list		**stack_a;
	t_list		**stack_b;

	foo = parsing(argv, argc);
	stack_a = malloc(sizeof(t_list **));
	stack_b = malloc(sizeof(t_list **));
	init_stack(stack_a, stack_b, foo, ft_len_arr(foo));
	sort_main(stack_a, stack_b);
	ft_free_arr(foo);
	delete_stacks(stack_a, stack_b);
	return (0);
}
