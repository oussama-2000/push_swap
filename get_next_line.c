/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamkhou <oamkhou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 23:55:41 by oamkhou           #+#    #+#             */
/*   Updated: 2026/01/03 13:30:28 by oamkhou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_buffer(char **buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	if (*buffer == NULL)
		return ;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if (!(*buffer)[i])
	{
		free(*buffer);
		*buffer = NULL;
		return ;
	}
	new_buffer = malloc(ft_strlen(*buffer) - i + 1);
	if (!new_buffer)
		return ;
	i++;
	j = 0;
	while ((*buffer)[i])
		new_buffer[j++] = (*buffer)[i++];
	new_buffer[j] = '\0';
	free(*buffer);
	*buffer = new_buffer;
}

int	ft_while(int fd, char **buffer)
{
	char	*str_read;
	int		bytes;

	bytes = 0;
	while (!search(*buffer, '\n'))
	{
		str_read = malloc(5);
		if (!str_read)
			return (-1);
		bytes = read(fd, str_read, 4);
		if (bytes == -1)
		{
			free(str_read);
			free(*buffer);
			*buffer = NULL;
			return (-1);
		}
		if (bytes == 0)
			return (free(str_read), 0);
		str_read[bytes] = '\0';
		*buffer = join(*buffer, str_read);
		if (!*buffer)
			return (free(str_read), free(*buffer), -1);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			state;

	state = 0;
	state = ft_while(fd, &buffer);
	if (state == -1)
		return (NULL);
	line = extract_line(buffer);
	update_buffer(&buffer);
	return (line);
}
