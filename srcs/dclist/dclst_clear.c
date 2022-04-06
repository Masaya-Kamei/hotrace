/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclst_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:27:27 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/05 13:05:25 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dclist.h"

void	dclst_clear(t_dclist **lst, void (*del)(void *))
{
	t_dclist	*sentinel;
	t_dclist	*current;
	t_dclist	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	sentinel = *lst;
	current = (*lst)->next;
	while (current != sentinel)
	{
		next = current->next;
		dclst_delone(current, del);
		current = next;
	}
	dclst_delone(sentinel, del);
	*lst = NULL;
}
