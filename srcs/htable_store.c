/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable_store.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:10:09 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/06 15:01:43 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static t_status	status_with_free(void *p1, void *p2, const t_status status)
{
	free(p1);
	free(p2);
	return (status);
}

static t_status	store_dict_to_htable(t_dclist **htable, char *key, char *value)
{
	const size_t	htable_index = hash_func(key);
	t_dict			*hit_dict;
	t_dclist		*new_lst;

	hit_dict = search_dict(htable[htable_index], key);
	if (hit_dict == NULL)
	{
		new_lst = dclst_new_size(sizeof(t_dict));
		if (new_lst == NULL)
			return (ERROR);
		((t_dict *)new_lst->p)->key = key;
		((t_dict *)new_lst->p)->value = value;
		dclst_addback(htable[htable_index], new_lst);
	}
	else
	{
		free(key);
		free(hit_dict->value);
		hit_dict->value = value;
	}
	return (SUCCESS);
}

t_status	store_to_htable(t_dclist **htable)
{
	char	*line;
	char	*key;
	int		gnl_status;

	key = NULL;
	while (1)
	{
		line = NULL;
		gnl_status = get_next_line(STDIN_FILENO, &line);
		if (gnl_status == -1)
			return (status_with_free(key, line, ERROR));
		else if (gnl_status == 0)
			return (status_with_free(key, line, EXIT));
		else if (line[0] == '\0')
			return (status_with_free(key, line, SUCCESS));
		if (key == NULL)
			key = line;
		else
		{
			if (store_dict_to_htable(htable, key, line) == ERROR)
				return (status_with_free(key, line, ERROR));
			key = NULL;
		}
	}
}
