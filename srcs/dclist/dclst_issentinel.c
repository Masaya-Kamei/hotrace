/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclst_is_sentinel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:59:47 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/06 12:01:09 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dclist.h"

bool	dclst_issentinel(t_dclist *lst, t_dclist *target)
{
	return (lst == target);
}
