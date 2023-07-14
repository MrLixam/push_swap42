/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:36 by lvincent          #+#    #+#             */
/*   Updated: 2023/07/11 13:19:07 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_content
{
	int	value;
	int	v_index;
}		t_content;

void		ft_error(void);

void		ft_sx(t_list **stack, int x);
void		ft_ss(t_list **stack_a, t_list **stack_b);
void		ft_px(t_list **stack_to, t_list **stack_from, int x);
void		ft_rx(t_list **stack, int x);
void		ft_rr(t_list **stack_a, t_list **stack_b);
void		ft_rrx(t_list **stack, int x);
void		ft_rrr(t_list **stack_a, t_list **stack_b);

void		init_stack(t_list **stk_a, t_list **stk_b, char **foo, int nb);
t_content	*init_struct(int value);

void		del(void *to_del);
void		delete_stacks(t_list **stack_a, t_list **stack_b);

char		**parsing(char **argv, int argc);
void		parsing2(char **arr);
int			ft_atoi_err(const char *str, int *error);

int			check_sort(t_list **stack, int max);
void		sort_main(t_list **stack_a, t_list **stack_b);
void		complex_sort(t_list **stack_a, t_list **stack_b);

size_t		read_value(t_list **stack, int index);
size_t		find_min(t_list **stack);
size_t		find_max(t_list **stack);

void		print_lst(t_list **stack);
#endif
