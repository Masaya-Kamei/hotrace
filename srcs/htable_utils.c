/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:36:01 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/06 14:53:55 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

size_t	hash_func(const char *s)
{
	static const uint64_t	offset = 14695981039346656037UL;
	static const uint64_t	prime = 1099511628211UL;
	uint64_t				hash;
	uint8_t					byte;

	hash = offset;
	while (*s)
	{
		byte = *s;
		hash ^= byte;
		hash *= prime;
		s++;
	}
	return (hash % HTABLE_SIZE);
}

t_dict	*search_dict(t_dclist *dict_lst, char *key)
{
	t_dclist	*lst;
	t_dict		*dict;

	lst = dclst_with_take_p(dict_lst->next, (void **)&dict);
	while (dclst_issentinel(dict_lst, lst) == 0)
	{
		if (ft_strcmp(dict->key, key) == 0)
			return (dict);
		lst = dclst_with_take_p(lst->next, (void **)&dict);
	}
	return (NULL);
}

