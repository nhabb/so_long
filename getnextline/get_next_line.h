/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:20:30 by wasmar            #+#    #+#             */
/*   Updated: 2024/10/28 10:10:57 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>  
# include <fcntl.h>  
# include <stdio.h>   
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*read_line(int fd, int *position,
				int *buffer_size, char *readbuffer);
char		*add_to_line(int line_len, char c, char *line_to_return);
ssize_t		read_buffer_function(int fd, int *position,
				int *buffer_size, char *buffer);
#	endif
