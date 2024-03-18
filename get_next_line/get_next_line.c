/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:25:15 by jpancorb          #+#    #+#             */
/*   Updated: 2023/11/05 13:28:49 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buff_read(int fd, char *stash)
{
	int		bytes_read;
	char	*buff;

	bytes_read = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_free(&stash));
	buff[0] = 0;
	while (bytes_read > 0 && !ft_strchr(buff, '\n'))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buff[bytes_read] = 0;
			stash = ft_strjoin(stash, buff);
		}
	}
	free(buff);
	if (bytes_read == -1)
		return (ft_free(&stash));
	return (stash);
}

char	*new_line(char *stash)
{
	char	*new_line;
	char	*line_feed;
	size_t	to_feed;

	line_feed = ft_strchr(stash, '\n');
	to_feed = (line_feed - stash) + 1;
	new_line = ft_substr(stash, 0, to_feed);
	if (!new_line)
		return (NULL);
	return (new_line);
}

char	*stash_left(char *stash)
{
	char	*rest;
	char	*line_feed;
	size_t	to_feed;

	line_feed = ft_strchr(stash, '\n');
	if (!line_feed)
	{
		rest = NULL;
		return (ft_free(&stash));
	}
	else
		to_feed = (line_feed - stash) + 1;
	if (!stash[to_feed])
		return (ft_free(&stash));
	rest = ft_substr(stash, to_feed, (ft_strlen(stash) - to_feed));
	ft_free(&stash);
	if (!rest)
		return (NULL);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((stash && !ft_strchr(stash, '\n')) || !stash)
		stash = buff_read(fd, stash);
	if (!stash)
		return (NULL);
	line = new_line(stash);
	if (!line)
		return (ft_free(&stash));
	stash = stash_left(stash);
	return (line);
}
