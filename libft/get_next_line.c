/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 02:42:50 by healeksa          #+#    #+#             */
/*   Updated: 2024/05/30 02:55:39 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char *reminder)
{
	int		read_res;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_res = 1;
	while (read_res != 0 && !(ft_strchr(reminder, '\n')))
	{
		read_res = read(fd, buff, BUFFER_SIZE);
		if (read_res == -1)
		{
			ft_free((void *)&reminder);
			free(buff);
			return (NULL);
		}
		buff[read_res] = '\0';
		reminder = ft_join(reminder, buff);
	}
	free(buff);
	return (reminder);
}

char	*processing(char *str)
{
	char	*proc_str;
	int		i;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	proc_str = ft_substr(str, 0, i + 1);
	return (proc_str);
}

char	*clean_reminder(char *reminder)
{
	int		i;
	int		len;
	char	*tmp;

	if (!reminder)
		return (NULL);
	len = ft_strlen(reminder);
	i = 0;
	while (reminder[i] != '\n' && reminder[i] != '\0')
		i++;
	if (!reminder[i])
	{
		free(reminder);
		return (NULL);
	}
	tmp = ft_substr(reminder, i + 1, len - i);
	free(reminder);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*reminder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_free((void *)&reminder);
		return (NULL);
	}
	reminder = read_file(fd, reminder);
	line = processing(reminder);
	reminder = clean_reminder(reminder);
	return (line);
}
