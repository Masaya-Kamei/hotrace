/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:46:37 by hyoshie           #+#    #+#             */
/*   Updated: 2022/04/06 14:53:21 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include "dclist.h"
# include "get_next_line.h"
# include "utils.h"
# include <errno.h>
# include <unistd.h>
# include <string.h>

# define HTABLE_SIZE 1000000

typedef enum e_status
{
	SUCCESS	= 0,
	ERROR	= 1,
	EXIT	= 2
}			t_status;

typedef struct	s_dict
{
	char	*key;
	char	*value;
}			t_dict;

t_status	store_to_htable(t_dclist **htable);
t_status	search_from_htable(t_dclist **htable);
size_t		hash_func(const char *str);
t_dict		*search_dict(t_dclist *dict_lst, char *key);

#endif /* HOTRACE_H */
