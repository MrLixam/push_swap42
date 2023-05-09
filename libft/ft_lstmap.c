/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvincent <lvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:40:42 by lvincent          #+#    #+#             */
/*   Updated: 2022/11/12 18:26:45 by lvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_link;
	t_list	*new_lst;

	new_lst = NULL;
	while (lst != NULL && del != NULL)
	{
		new_link = ft_lstnew((*f)(lst->content));
		if (new_link == NULL)
		{
			ft_lstclear(&new_lst, del);
			break ;
		}
		ft_lstadd_back(&new_lst, new_link);
		lst = lst->next;
	}
	return (new_lst);
}
