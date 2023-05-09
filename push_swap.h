/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:25:36 by lvincent          #+#    #+#             */
/*   Updated: 2023/05/09 17:37:42 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

int		ft_lst_len(int *lst);
void	ft_sx(int *stack);
void	ft_ss(int *stack_a, int *stack_b);
void	ft_pa(int *stack_a, int *stack_b);
void	ft_pb(int *stack_a, int *stack_b);
void	ft_rx(int *stack);
void	ft_rr(int *stack_a, int *stack_b);