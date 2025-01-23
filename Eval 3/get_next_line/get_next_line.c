/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

// ---------------PROTOTYPAGE---------------
char		*get_next_line(int fd);
char		*ft_strdup(const char *src);
// -----------------------------------------

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buf_pos;
	static int	buf_read;
	char		line[20000];
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buf_pos >= buf_read)
		{
			buf_pos = 0;
			buf_read = read(fd, buffer, BUFFER_SIZE);
			if (buf_read < 0)
				return (NULL);
			if (buf_read == 0)
				break ;
		}
		line[i++] = buffer[buf_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
