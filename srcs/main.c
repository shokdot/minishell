/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:25:54 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/27 22:16:00 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	char	*_line;

	if (argc != 1 || !argv[0])
		return (printf("lolll\n"), 1);
	(void)envp;
	while (1)
	{
		line = readline(PROMPT);
		if (line == NULL || line[0] == '\0')
			continue ;
		add_history(line);
		_line = tokenization(line);
		printf("%s\n", _line);
		if (!ft_strcmp(_line, "exit"))
		{
			ft_free((void *)&_line);
			exit(1);
		}
	}
}
