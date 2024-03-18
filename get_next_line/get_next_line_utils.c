/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:10:32 by jpancorb          #+#    #+#             */
/*   Updated: 2023/11/05 13:17:30 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	y;
	char	*newstr;

	i = 0;
	y = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	newstr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return (ft_free(&s1));
	while (s1[i])
		newstr[i++] = s1[y++];
	i = 0;
	while (s2[i])
		newstr[y++] = s2[i++];
	newstr[y] = 0;
	free(s1);
	return (newstr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	y;
	char	*subs;

	i = 0;
	y = 0;
	while (s[y])
		y++;
	if (y < start)
		len = 0;
	if (len > y - start)
		len = y - start;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (subs == NULL)
		return (NULL);
	while (start < y && i < len)
		subs[i++] = s[start++];
	subs[i] = '\0';
	return (subs);
}
