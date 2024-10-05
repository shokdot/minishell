/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:25:54 by healeksa          #+#    #+#             */
/*   Updated: 2024/10/06 00:11:04 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	argument_check(int argc, char **argv)
{
	if (argc != 1 || !argv[0])
	{
		ft_putendl_fd("Minishell can't take argumensts.", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)envp;
	argument_check(argc, argv);
	signal_handle();
	while (1)
	{
		line = readline(PROMPT);
		if (!line)
		{
			ft_putendl_fd("exit", 1);
			break ;
		}
		if (line[0] == '\0')
			continue ;
		add_history(line);
		cmd_execution(line, envp);
	}
}
