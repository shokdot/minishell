/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:35:08 by healeksa          #+#    #+#             */
/*   Updated: 2024/01/29 17:00:50 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_srch(char c, const char *set)
{
	if (!*set)
		return (0);
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_srch(s1[start], set))
		start++;
	while (end > 0 && ft_srch(s1[end], set))
		end--;
	if (end < start)
		return (ft_strdup(""));
	return (ft_substr(s1, start, (end - start + 1)));
}
