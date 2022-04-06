/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclst_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:22:38 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/05 10:25:58 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dclist.h"

t_dclist	*dclst_pop(t_dclist *lst)
{
	dclst_link(lst->prev, lst->next);
	lst->prev = lst;
	lst->next = lst;
	return (lst);
}
