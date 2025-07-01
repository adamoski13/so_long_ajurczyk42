/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurczyk <ajurczyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:24:03 by ajurczyk          #+#    #+#             */
/*   Updated: 2025/07/01 15:11:19 by ajurczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_buffer_size_line(int fd, char *buffer_line, char *source)
{
	ssize_t	s_read;
	char	*temp;

	s_read = 1;
	while (s_read > 0)
	{
		s_read = read(fd, source, BUFFER_SIZE);
		if (s_read == -1)
		{
			free(buffer_line);
			return (NULL);
		}
		else if (s_read == 0)
			break ;
		source[s_read] = 0;
		if (!buffer_line)
			buffer_line = ft_strdup("");
		temp = buffer_line;
		buffer_line = ft_strjoin(temp, source);
		// free(temp);
		// temp = NULL;
		if (ft_strchr(source, '\n'))
			break ;
	}
	return (buffer_line);
}

static char	*cut_buffer_line(char *line)
{
	char	*buffer_line;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0)
		return (NULL);
	buffer_line = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*buffer_line == 0)
	{
		free(buffer_line);
		buffer_line = NULL;
	}
	return (buffer_line);
}

static char	*cut_line(char *line)
{
	size_t	i;
	char	*temp2;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	temp2 = ft_substr(line, 0, i);
	free(line);
	line = NULL;
	return (temp2);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*source;
	static char	*buffer_line;

	source = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!source)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer_line);
		free(source);
		buffer_line = NULL;
		source = NULL;
		return (NULL);
	}
	line = read_buffer_size_line(fd, buffer_line, source);
	free(source);
	source = NULL;
	if (!line)
		return (NULL);
	buffer_line = cut_buffer_line(line);
	line = cut_line(line);
	return (line);
}
