/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:50:48 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/27 17:48:12 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char **argv)
{
	char		**foo;
	t_list		**stack;
	t_list		**stack2;

	foo = parsing(argv, argc);
	stack = malloc(sizeof(t_list **));
	stack2 = malloc(sizeof(t_list **));
	init_stack(stack, stack2, foo, ft_len_arr(foo));
	ft_free_arr(foo);
	delete_stacks(stack, stack2);
	return (0);
}
