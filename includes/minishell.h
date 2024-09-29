/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:27:04 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/29 13:53:31 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PROMPT "minishell>$ "

// struct

typedef struct s_shell
{
	t_list	*cmd_line;
}			t_shell;

// init

void		shell_init(t_shell *minishell);

// tokenization
char		*tokenization(char *line);

#endif
