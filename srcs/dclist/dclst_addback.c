/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclst_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:15:58 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/04 14:42:30 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dclist.h"

void	dclst_addback(t_dclist *lst, t_dclist *new_lst)
{
	if (new_lst == NULL)
		return ;
	dclst_link(lst->prev, new_lst);
	dclst_link(new_lst, lst);
}
