/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: braugust <braugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:50:19 by braugust          #+#    #+#             */
/*   Updated: 2024/06/19 18:14:57 by braugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*initialize_buffer(char *buffer, int bytes_read)
{
	if (buffer == NULL)
	{
		buffer = (char *)malloc(sizeof(char) * (bytes_read + 1));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	return (buffer);
}

char	*append_to_buffer(char *buffer, char *buff)
{
	char	*temp;

	temp = buffer;
	buffer = ft_strjoin(buffer, buff);
	free(temp);
	return (buffer);
}

int	read_and_update_buffer(int fd, char **buffer, char *buff)
{
	int	bytes_read;

	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read == -1)
		return (-1);
	buff[bytes_read] = '\0';
	*buffer = initialize_buffer(*buffer, bytes_read);
	if (!(*buffer))
		return (-1);
	*buffer = append_to_buffer(*buffer, buff);
	if (!(*buffer))
		return (-1);
	return (bytes_read);
}

char	*read_line(int fd, char *buffer)
{
	char	*buff;
	int		read_result;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_result = 1;
	while (!ft_strchr(buffer, '\n') && read_result != 0)
	{
		read_result = read_and_update_buffer(fd, &buffer, buff);
		if (read_result == -1)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_new_line(buffer);
	return (line);
}
