/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: irsander <irsander@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/14 18:22:14 by irissanders   #+#    #+#                 */
/*   Updated: 2023/11/20 10:32:58 by irissanders   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

//get_next_line.c
char 	*get_next_line(int fd);
char	*cut_line(char *s, char *newline);
char	*find_line(char *s);

//get_next_line_utils.c
int		ft_strlen(char *s);
int		ft_strchr(const char *s, int c);
char	*ft_strcat(char *s, char *buf);
void	ft_strcpy(char *line, char *buf);

#endif
