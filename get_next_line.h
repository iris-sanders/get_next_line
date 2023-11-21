/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: irsander <irsander@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/14 18:22:14 by irissanders   #+#    #+#                 */
/*   Updated: 2023/11/21 22:33:13 by irissanders   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

//get_next_line.c

/// @brief creates a new string with all characters found after the newline
/// character.
/// @param s static variable that contains the string read from the fd
/// @param newline the new string created in find_line 
///(string incl newline character), used to calculate the size for memory
/// allocation. Also used as a starting index for the new string 'line' to 
/// copy into until the end of the string 's'.
/// @return the newline created from string 's', consisting everything after
/// the newline character until the end of the string 's'.
char	*cut_line(char *s, char *newline);

/// @brief Finds the new line in s. Removes everything after the newline 
/// character in the string 's', so that a new string is created including 
/// the newline character. 
/// @param s static variable that contains the string read from the fd,
/// in which the new line is to be found.
/// @return the newline including the newline character.
char	*find_line(char *s);

/// @brief reads from fd into buffer and concatenates the buffer with 
/// string 's' until it finds a newline character in the string 's'.
/// @param s static variable that contains the string read from the fd
/// @param fd file descriptor to be read from
/// @return string s
char	*ft_read(char *s, int fd);

/// @brief creates the static variable 's'. Stores everything read from fd 
/// into 's'. Finds the line including the newline character in string s 
/// and returns this. then creates a new string with the remainder after the
/// newline character and stores it in s so it remembers where it left off 
/// reading from the fd.
/// @param fd file descriptor to be read from
/// @return the string found in 's' including the newline character.
char	*get_next_line(int fd);

//get_next_line_utils.c

/// @brief counts the length of string s
/// @param s the string which length is to be counted
/// @return the number of characters in the string before the terminating
/// NULL character
int		ft_strlen(char *s);

/// @brief finds the integer c in string s
/// @param s the string to search
/// @param c the integer to find within the string s
/// @return -1 if c is not found, index number if c is found
int		ft_strchr(const char *s, int c);

/// @brief concatenates two strings while allocating enough space for 's'.
/// @param s static variable that may contain a part of the previous read 
/// string from fd, to be concatenated with buf.
/// @param buf string of buffer size, which is read from fd. Now to copy 
/// after the existing string 's'
/// @return s, which contains the result of the concatenation of buf and s
char	*ft_strcat(char *s, char *buf);

/// @brief frees s, sets it to NULL and returns NULL.
/// @param s static variable that contains the string read from the fd
/// @return NULL
void	*ft_free(char **s);

#endif
