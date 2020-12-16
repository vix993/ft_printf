/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:50:06 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/09 17:40:37 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*temp;
	t_list		*head;
	t_list		*new;

	if (lst)
	{
		temp = lst;
		if (!(head = ft_lstnew(f(temp->content))))
			return (NULL);
		temp = temp->next;
		while (temp)
		{
			if (!(new = ft_lstnew(f(temp->content))))
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, new);
			temp = temp->next;
		}
		return (head);
	}
	return (NULL);
}
