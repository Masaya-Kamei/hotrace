/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:42:48 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/06 15:06:07 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static int	status_with_errout(char *errmsg, const int status)
{
	ft_putendl_fd(errmsg, STDERR_FILENO);
	return (status);
}

static void	dict_free(void *dict)
{
	if (dict == NULL)
		return ;
	free(((t_dict *)dict)->key);
	free(((t_dict *)dict)->value);
	free(dict);
}

static void	clear_htable(t_dclist **htable, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dclst_clear(&htable[i], dict_free);
		i++;
	}
	free(htable);
}

static t_dclist	**init_htable(void)
{
	size_t		i;
	t_dclist	**htable;

	htable = (t_dclist **)malloc(sizeof(t_dclist *) * HTABLE_SIZE);
	if (htable == NULL)
		return (NULL);
	i = 0;
	while (i < HTABLE_SIZE)
	{
		htable[i] = dclst_new(NULL);
		if (htable[i] == NULL)
		{
			clear_htable(htable, i);
			return (NULL);
		}
		i++;
	}
	return (htable);
}

int	main(void)
{
	t_dclist	**htable;
	t_status	status;

	htable = init_htable();
	if (htable == NULL)
		return (status_with_errout(strerror(errno), 1));
	status = store_to_htable(htable);
	if (status == SUCCESS)
		status = search_from_htable(htable);
	clear_htable(htable, HTABLE_SIZE);
	if (status == ERROR)
		return (status_with_errout(strerror(errno), 1));
	return (0);
}
