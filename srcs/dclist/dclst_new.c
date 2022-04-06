/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclst_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:41:21 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/04 16:43:54 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dclist.h"

t_dclist	*dclst_new(void *p)
{
	t_dclist	*new_lst;

	new_lst = (t_dclist *)malloc(sizeof(t_dclist));
	if (new_lst == NULL)
		return (NULL);
	new_lst->p = p;
	new_lst->prev = new_lst;
	new_lst->next = new_lst;
	return (new_lst);
}
