/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: irsander <irsander@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/14 18:21:00 by irissanders   #+#    #+#                 */
/*   Updated: 2023/11/20 10:32:13 by irissanders   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
