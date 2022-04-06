/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclst_new_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:16:30 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/05 09:18:47 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dclist.h"

t_dclist	*dclst_new_size(size_t size)
{
	t_dclist	*new_lst;

	new_lst = (t_dclist *)malloc(sizeof(t_dclist));
	if (new_lst == NULL)
		return (NULL);
	new_lst->p = malloc(size);
	if (new_lst->p == NULL)
	{
		free(new_lst);
		return (NULL);
	}
	new_lst->prev = new_lst;
	new_lst->next = new_lst;
	return (new_lst);
}
