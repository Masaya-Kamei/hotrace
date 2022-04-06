/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htable_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:23:50 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/06 14:54:37 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static void	search_dict_from_htable(t_dclist **htable, char *key)
{
	const size_t	htable_index = hash_func(key);
	t_dict			*hit_dict;

	hit_dict = search_dict(htable[htable_index], key);
	if (hit_dict == NULL)
	{
		ft_putstr_fd(key, STDOUT_FILENO);
		ft_putendl_fd(": Not found.", STDOUT_FILENO);
	}
	else
		ft_putendl_fd(hit_dict->value, STDOUT_FILENO);
}

t_status	search_from_htable(t_dclist **htable)
{
	char	*key;
	int		gnl_status;

	gnl_status = 1;
	while (gnl_status >= 1)
	{
		key = NULL;
		gnl_status = get_next_line(STDIN_FILENO, &key);
		if (gnl_status == -1)
		{
			free(key);
			return (ERROR);
		}
		if (key[0])
			search_dict_from_htable(htable, key);
		free(key);
	}
	return (SUCCESS);
}
