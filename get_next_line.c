/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: irsander <irsander@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/14 18:21:00 by irissanders   #+#    #+#                 */
/*   Updated: 2023/11/19 19:49:20 by irissanders   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*cut_line(char *s, char *newline)
{
	int		i;
	int		j;
	char	*line;
	int		size;

	size = ft_strlen(s) - ft_strlen(newline);
	i = ft_strlen(newline);
	j = 0;
	line = malloc((size + 1) * sizeof(char));
	if (!line)
	{
		free(s);
		return (NULL);
	}
	while (s[i])
		line[j++] = s[i++];
	line[j] = '\0';
	free(s);
	return (line);
}

static int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!s[i])
		return (-1);
	return (i);
}

char	*find_line(char *s)
{
	int		i;
	int		j;
	char	*line;

	j = ft_strchr(s, '\n') + 1;
	if (j == 0)
		j = ft_strlen(s);
	line = malloc((j + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		line[j++] = s[i++];
	if (s[i] == '\n')
		line[j++] = s[i++];
	line[j] = '\0';
	return (line);
}

void	ft_strcpy(char *line, char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(line);
	while (buf[i])
		line[j++] = buf[i++];
	line[j] = '\0';
}

char	*ft_strcat(char *s, char *buf)
{
	int				i;
	int				j;
	char			*temp;

	i = 0;
	j = 0;
	temp = malloc((ft_strlen(s) + ft_strlen(buf) +1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (s[i])
		temp[j++] = s[i++];
	i = 0;
	while (buf[i])
		temp[j++] = buf[i++];
	temp[j] = '\0';
	return (temp);
}

char	*get_next_line(int fd)
{
	static char		*s = NULL;
	char			buf[BUFFER_SIZE +1];
	int				read_bytes;
	char			*line;
	char			*temp;

	line = NULL;
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s)
	{
		s = malloc(sizeof(char));
		if (!s)
			return (NULL);
		*s = '\0';
	}
	while (ft_strchr(s, '\n') == -1)
	{
		read_bytes = read(fd, &buf[0], BUFFER_SIZE);
		if (read_bytes == -1 || (read_bytes == 0 && *s == '\0'))
		{
			free (s);
			s = NULL;
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		temp = ft_strcat(s, buf);
		free(s);
		s = NULL;
		if (!temp)
			return (NULL);
		s = temp;
	}
	line = find_line(s);
	if (!line)
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	s = cut_line(s, line);
	if (!s)
	{
		free (line);
		return (NULL);
	}
	return (line);
}
