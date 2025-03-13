/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmar <wasmar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:20:26 by wasmar            #+#    #+#             */
/*   Updated: 2024/06/26 20:23:28 by wasmar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	readbuffer[BUFFER_SIZE];
	static int	position = 0;
	static int	buffer_size = 0;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	return (read_line(fd, &position, &buffer_size, readbuffer));
}
