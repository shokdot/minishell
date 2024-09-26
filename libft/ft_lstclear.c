/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:41:05 by healeksa          #+#    #+#             */
/*   Updated: 2024/01/30 13:45:28 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*present;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		present = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = present;
	}
	free(*lst);
}
