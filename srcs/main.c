/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:25:54 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/25 18:06:37 by healeksa         ###   ########.fr       */
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
		line = readline(SH_PROMPT);
		if (line == NULL)
			break ;
		if (line[0] != '\0')
			add_history(line);
		if (!ft_strcmp(line, "exit"))
		{
			free(_line);
			free(line);
			exit(1);
		}
		_line = ft_strtrim(line, " \t");
		free(line);
		printf("%s\n", _line);
		free(_line);
	}
}
