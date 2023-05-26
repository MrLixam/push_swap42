/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:36 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/26 13:00:11 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_content
{
	int	value;
	int	v_index;
}		t_content;

void		ft_sx(t_list **stack);
void		ft_ss(t_list **stack_a, t_list **stack_b);
void		ft_px(t_list **stack_to, t_list **stack_from);
void		ft_rx(t_list **stack);
void		ft_rr(t_list **stack_a, t_list **stack_b);
void 		ft_rrx(t_list **stack);
void		ft_rrr(t_list **stack_a, t_list **stack_b);
void		init_stack(t_list **stack_a, t_list **stack_b, char **argv, int argc);
t_content	*init_struct(int value);
void		del(void *to_del);
void		delete_stacks(t_list **stack_a, t_list **stack_b);