/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:54:57 by mkamei            #+#    #+#             */
/*   Updated: 2022/04/06 14:42:31 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	i = 0;
	while ((u_s1[i] != 0 && u_s2[i] != 0))
	{
		if (u_s1[i] != u_s2[i])
			return (u_s1[i] - u_s2[i]);
		i++;
	}
	return (u_s1[i] - u_s2[i]);
}
