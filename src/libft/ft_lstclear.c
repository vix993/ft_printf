/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnascime <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 20:40:11 by vnascime          #+#    #+#             */
/*   Updated: 2020/02/09 17:36:53 by vnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*tmphead;

	tmphead = *lst;
	while (tmphead)
	{
		temp = tmphead->next;
		if (del)
		{
			del(tmphead->content);
		}
		free(tmphead);
		tmphead = temp;
	}
	*lst = NULL;
}
