/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclst_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:20:12 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/04 14:34:53 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dclist.h"

void	dclst_link(t_dclist *front, t_dclist *back)
{
	front->next = back;
	back->prev = front;
}
