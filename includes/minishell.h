/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:27:04 by healeksa          #+#    #+#             */
/*   Updated: 2024/10/06 00:11:23 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PROMPT "minishell>$ "

// struct

// init

// tokenization

void	cmd_execution(char *line, char **envp);
void	__pwd(char **env);
void	__env(char **envp);
void	__exit(int status);
void	__export(char **envp);

// signal

void	signal_handle(void);

#endif
