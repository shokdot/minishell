/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 22:08:50 by healeksa          #+#    #+#             */
/*   Updated: 2024/09/27 22:14:07 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*tokenization(char *line)
{
	char	*_line;

	_line = ft_strtrim(line, " \t");
	ft_free((void *)&line);
	return (_line);
}
