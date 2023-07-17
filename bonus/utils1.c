/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:11:08 by lvincent          #+#    #+#             */
/*   Updated: 2023/07/16 19:17:40 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_sx(t_list **stack)
{
	t_list		*first;
	t_list		*i;
	t_content	*tmp;

	if (stack)
	{
		first = *stack;
		if (first->next != NULL)
		{
			i = first->next;
			tmp = first->content;
			first->content = i->content;
			i->content = tmp;
		}
	}
}

void	del(void *to_del)
{
	free(to_del);
}

void	ft_rx(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) > 1)
	{
		tmp = ft_lstlast(*stack);
		tmp->next = *stack;
		tmp = tmp->next;
		*stack = tmp->next;
		tmp->next = NULL;
	}
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
	while ((*str == '-' || *str == '+') || *str == '0')
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
