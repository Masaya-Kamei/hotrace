/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dclist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:08:29 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/06 14:57:21 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DCLIST_H
# define DCLIST_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_dclist
{
	void			*p;
	struct s_dclist	*prev;
	struct s_dclist	*next;
}					t_dclist;

t_dclist	*dclst_new(void	*p);
void		dclst_addback(t_dclist *lst, t_dclist *new_lst);
t_dclist	*dclst_last(t_dclist *lst);
void		dclst_delone(t_dclist *lst, void (*del)(void *));
void		dclst_clear(t_dclist **lst, void (*del)(void *));
bool		dclst_exist(t_dclist *lst);
void		dclst_link(t_dclist *front, t_dclist *back);
t_dclist	*dclst_new_size(size_t size);
t_dclist	*dclst_first(t_dclist *lst);
bool		dclst_issentinel(t_dclist *lst, t_dclist *target);
t_dclist	*dclst_pop(t_dclist *lst);
t_dclist	*dclst_popdel_next(t_dclist *lst, void (*del)(void *));
t_dclist	*dclst_with_take_p(t_dclist *lst, void **p_ptr);

#endif
