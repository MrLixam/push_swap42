/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:23:31 by lvincent          #+#    #+#             */
/*   Updated: 2023/06/07 15:54:24 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_arg(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (!ft_strncmp(arg, "sa", len || !ft_strncmp(arg, "sb", len)))
		return (1);
	if (!ft_strncmp(arg, "pa", len || !ft_strncmp(arg, "pb", len)))
		return (1);
	if (!ft_strncmp(arg, "ra", len || !ft_strncmp(arg, "rb", len)))
		return (1);
	if (!ft_strncmp(arg, "rra", len || !ft_strncmp(arg, "rrb", len)))
		return (1);
	if (!ft_strncmp(arg, "rr", len || !ft_strncmp(arg, "rrr", len)))
		return (1);
	if (!ft_strncmp(arg, "ss", len))
		return (1);
	else
		return (0);
}

static void	choose_arg(char *s, t_list **sa, t_list **sb)
{
	if (!ft_strncmp(s, "sa", 2) || !ft_strncmp(s, "ss", 2))
		ft_sx(sa);
	if (!ft_strncmp(s, "sb", 2) || !ft_strncmp(s, "ss", 2))
		ft_sx(sb);
	if (!ft_strncmp(s, "ra", 2) || !ft_strncmp(s, "rr\n", 3))
		ft_rx(sa);
	if (!ft_strncmp(s, "rb", 2) || !ft_strncmp(s, "rr\n", 3))
		ft_rx(sb);
	if (!ft_strncmp(s, "rra", 3) || !ft_strncmp(s, "rrr", 3))
		ft_rrx(sa);
	if (!ft_strncmp(s, "rrb", 3) || !ft_strncmp(s, "rrr", 3))
		ft_rrx(sb);
	if (!ft_strncmp(s, "pa", 2))
		ft_px(sa, sb);
	if (!ft_strncmp(s, "pb", 2))
		ft_px(sb, sa);
}

static int	instructions(t_list **sa, t_list **sb)
{
	char	*arg;

	arg = get_next_line(0);
	while (arg)
	{
		if (check_arg(arg))
		{
			choose_arg(arg, sa, sb);
			free(arg);
			arg = get_next_line(0);
		}
		else
		{
			free(arg);
			return (-1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char		**foo;
	t_list		**stack_a;
	t_list		**stack_b;
	int			i;

	i = -1;
	foo = parsing(argv, argc);
	stack_a = malloc(sizeof(t_list **));
	stack_b = malloc(sizeof(t_list **));
	if (!stack_a || !stack_b)
	{
		delete_stacks(stack_a, stack_b);
		ft_error();
	}
	init_stack(stack_a, stack_b, foo, ft_len_arr(foo));
	i = instructions(stack_a, stack_b);
	if (!check_sort(stack_a, ft_lstsize(*stack_a)) && !i)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_arr(foo);
	delete_stacks(stack_a, stack_b);
	return (0);
}
