/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 23:04:42 by lvincent          #+#    #+#             */
/*   Updated: 2023/06/06 22:57:10 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_content
{
	int	value;
	int	v_index;
}		t_content;

void		ft_error(void);

void		ft_sx(t_list **stack);
void		ft_px(t_list **stack_to, t_list **stack_from);
void		ft_rx(t_list **stack);
void		ft_rrx(t_list **stack);

int			check_sort(t_list **stack, int max);

t_content	*init_struct(int value);
void		init_stack(t_list **stk_a, t_list **stk_b, char **foo, int nb);
size_t		read_value(t_list **stack, int index);

char		**parsing(char **argv, int argc);
void		parsing2(char **arr);

void		del(void *to_del);
void		delete_stacks(t_list **stack_a, t_list **stack_b);

#endif