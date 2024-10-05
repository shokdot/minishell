/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:09:31 by healeksa          #+#    #+#             */
/*   Updated: 2024/10/06 00:11:02 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_execution(char *line, char **envp)
{
	if (ft_strcmp(line, "pwd") == 0)
		__pwd(envp);
	else if (ft_strcmp(line, "env") == 0)
		__env(envp);
	else if (ft_strcmp(line, "exit") == 0)
		__exit(1);
	else if (ft_strcmp(line, "export") == 0)
		__export(envp);
}
