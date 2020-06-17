/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:49:25 by avornane          #+#    #+#             */
/*   Updated: 2019/11/08 10:30:59 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*fresh;
	t_list		*list;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	fresh = list;
	lst = lst->next;
	while (lst)
	{
		list->next = f(lst);
		lst = lst->next;
		list = list->next;
	}
	free(list);
	return (fresh);
}
