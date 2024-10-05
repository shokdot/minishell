/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:05:35 by healeksa          #+#    #+#             */
/*   Updated: 2024/10/05 21:55:34 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	__pwd(char **env)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	if (dir)
	{
		printf("%s\n", dir);
		free(dir);
		return ;
	}
	else
	{
		// change error status
		perror("pwd");
		return ;
	}
}
