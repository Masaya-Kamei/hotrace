/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclst_delone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:48:51 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/04 14:51:14 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dclist.h"

void	dclst_delone(t_dclist *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (del)
		del(lst->p);
	free(lst);
}
