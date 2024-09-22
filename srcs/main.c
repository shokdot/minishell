/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:25:54 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/23 00:47:34 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	while (1)
	{
		line = readline(SH_PROMPT);
		if (line == NULL)
			break ;
		if (line[0] != '\0')
			add_history(line);
		printf("%s\n", line);
	}
}
