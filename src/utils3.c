/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:22:04 by lvincent          #+#    #+#             */
/*   Updated: 2023/07/14 19:04:12 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_list **stack)
{
	t_list		*head;
	t_content	*content;

	head = *stack;
	ft_printf("start of list\n");
	while (head != NULL)
	{
		content = head->content;
		ft_printf("%d\n", content->value);
		head = head->next;
	}
	ft_printf("end of list\n\n");
}

size_t	find_max(t_list **stack)
{
	size_t	max;
	t_list	*head;
	size_t	i;

	head = *stack;
	max = 0;
	i = 0;
	while (head != NULL)
	{
		if (read_value(stack, max) < read_value(stack, i))
			max = i;
		i++;
		head = head->next;
	}
	return (max);
}

void	ft_px(t_list **stack_to, t_list **stack_from, int x)
{
	t_list		*new;
	t_list		*tmp;
	t_content	*temp;
	t_content	*new_cnt;

	if (*stack_from)
	{
		tmp = *stack_from;
		temp = tmp ->content;
		new_cnt = init_struct(temp->value);
		new_cnt->v_index = temp->v_index;
		new = ft_lstnew(new_cnt);
		ft_lstadd_front(stack_to, new);
		*stack_from = tmp->next;
		ft_lstdelone(tmp, &del);
	}
	if (x == 1)
		ft_printf("pa\n");
	if (x == 2)
		ft_printf("pb\n");
}

int	ft_atoi_err(const char *str, int *error)
{
	int	nb;
	int	sign;
	int	temp;

	nb = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (!ft_strncmp(str, "2147483648", ft_strlen(str)) && sign == -1)
		return (-2147483648);
	while (ft_isdigit(*str))
	{
		temp = nb;
		nb = nb * 10 + (*str++ - '0');
		if (nb / 10 != temp)
			*error = 1;
	}
	if (*str)
		*error = 1;
	return (nb * sign);
}
